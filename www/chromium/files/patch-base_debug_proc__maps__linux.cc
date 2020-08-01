--- base/debug/proc_maps_linux.cc.orig	2020-07-07 21:57:30 UTC
+++ base/debug/proc_maps_linux.cc
@@ -13,7 +13,7 @@
 #include "base/strings/string_split.h"
 #include "build/build_config.h"
 
-#if defined(OS_LINUX) || defined(OS_ANDROID)
+#if defined(OS_LINUX) || defined(OS_BSD) || defined(OS_ANDROID)
 #include <inttypes.h>
 #endif
 
@@ -29,6 +29,11 @@
 namespace base {
 namespace debug {
 
+#if defined(OS_BSD)
+const char kProcSelfMapsPath[] = "/proc/curproc/map";
+#else
+const char kProcSelfMapsPath[] = "/proc/self/maps";
+
 // Scans |proc_maps| starting from |pos| returning true if the gate VMA was
 // found, otherwise returns false.
 static bool ContainsGateVMA(std::string* proc_maps, size_t pos) {
@@ -44,15 +49,16 @@ static bool ContainsGateVMA(std::string* proc_maps, si
   return false;
 #endif
 }
+#endif
 
 bool ReadProcMaps(std::string* proc_maps) {
   // seq_file only writes out a page-sized amount on each call. Refer to header
   // file for details.
   const long kReadSize = sysconf(_SC_PAGESIZE);
 
-  base::ScopedFD fd(HANDLE_EINTR(open("/proc/self/maps", O_RDONLY)));
+  base::ScopedFD fd(HANDLE_EINTR(open(kProcSelfMapsPath, O_RDONLY)));
   if (!fd.is_valid()) {
-    DPLOG(ERROR) << "Couldn't open /proc/self/maps";
+    DPLOG(ERROR) << "Couldn't open " << kProcSelfMapsPath;
     return false;
   }
   proc_maps->clear();
@@ -66,7 +72,7 @@ bool ReadProcMaps(std::string* proc_maps) {
 
     ssize_t bytes_read = HANDLE_EINTR(read(fd.get(), buffer, kReadSize));
     if (bytes_read < 0) {
-      DPLOG(ERROR) << "Couldn't read /proc/self/maps";
+      DPLOG(ERROR) << "Couldn't read " << kProcSelfMapsPath;
       proc_maps->clear();
       return false;
     }
@@ -77,6 +83,7 @@ bool ReadProcMaps(std::string* proc_maps) {
     if (bytes_read == 0)
       break;
 
+#if !defined(OS_BSD)
     // The gate VMA is handled as a special case after seq_file has finished
     // iterating through all entries in the virtual memory table.
     //
@@ -87,6 +94,7 @@ bool ReadProcMaps(std::string* proc_maps) {
     // Avoid this by searching for the gate VMA and breaking early.
     if (ContainsGateVMA(proc_maps, pos))
       break;
+#endif
   }
 
   return true;
@@ -115,10 +123,32 @@ bool ParseProcMaps(const std::string& input,
     MappedMemoryRegion region;
     const char* line = lines[i].c_str();
     char permissions[5] = {'\0'};  // Ensure NUL-terminated string.
+    int path_index = 0;
+
+#if defined(OS_BSD)
+    if (lines[i].empty())
+      continue;
+
+
+    char cow;
+
+    // Format:
+    //
+    // start    end      resident private_resident obj                perms ref_count shadow_count flags  cow needs_copy type  fullpath cred ruid
+    // 0x200000 0x202000 2        6                0xfffff80005be9000 r--   3         1            0x1000 COW NC         vnode /bin/cat NCH  -1
+    //
+    if (sscanf(line, "%" SCNxPTR " %" SCNxPTR " %*ld %*ld %*llx %3c %*d %*d %*x %c%*s %*s %*s %n",
+	       &region.start, &region.end, permissions, &cow, &path_index) < 4) {
+      DPLOG(WARNING) << "sscanf failed for line: " << line;
+      return false;
+    }
+
+    const char* fullpath = line + path_index;
+    const char* cred     = strchr(fullpath, ' ');
+#else
     uint8_t dev_major = 0;
     uint8_t dev_minor = 0;
     long inode = 0;
-    int path_index = 0;
 
     // Sample format from man 5 proc:
     //
@@ -134,6 +164,7 @@ bool ParseProcMaps(const std::string& input,
       DPLOG(WARNING) << "sscanf failed for line: " << line;
       return false;
     }
+#endif
 
     region.permissions = 0;
 
@@ -152,14 +183,31 @@ bool ParseProcMaps(const std::string& input,
     else if (permissions[2] != '-')
       return false;
 
+#if defined(OS_BSD)
+    if (cow == 'C') {
+      region.permissions |= MappedMemoryRegion::PRIVATE;
+    } else if (cow != 'N') {
+      DPLOG(WARNING) << "unknown value for COW in line " << line << ": " << cow;
+      return false;
+    }
+#else
     if (permissions[3] == 'p')
       region.permissions |= MappedMemoryRegion::PRIVATE;
     else if (permissions[3] != 's' && permissions[3] != 'S')  // Shared memory.
       return false;
+#endif
 
     // Pushing then assigning saves us a string copy.
     regions.push_back(region);
+#if defined(OS_BSD)
+    if (cred != nullptr) {
+      regions.back().path.assign(line + path_index, cred - fullpath);
+    } else {
+      regions.back().path.assign(line + path_index);
+    }
+#else
     regions.back().path.assign(line + path_index);
+#endif
   }
 
   regions_out->swap(regions);
