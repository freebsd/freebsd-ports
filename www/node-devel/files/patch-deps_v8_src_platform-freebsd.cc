--- deps/v8/src/base/platform/platform-freebsd.cc.orig	2015-01-30 06:13:10 UTC
+++ deps/v8/src/base/platform/platform-freebsd.cc
@@ -131,23 +131,23 @@ std::vector<OS::SharedLibraryAddress> OS
     addr_buffer[0] = '0';
     addr_buffer[1] = 'x';
     addr_buffer[10] = 0;
-    int result = read(fd, addr_buffer + 2, 8);
-    if (result < 8) break;
+    ssize_t bytes_read = read(fd, addr_buffer + 2, 8);
+    if (bytes_read < 8) break;
     unsigned start = StringToLong(addr_buffer);
-    result = read(fd, addr_buffer + 2, 1);
-    if (result < 1) break;
+    bytes_read = read(fd, addr_buffer + 2, 1);
+    if (bytes_read < 1) break;
     if (addr_buffer[2] != '-') break;
-    result = read(fd, addr_buffer + 2, 8);
-    if (result < 8) break;
+    bytes_read = read(fd, addr_buffer + 2, 8);
+    if (bytes_read < 8) break;
     unsigned end = StringToLong(addr_buffer);
     char buffer[MAP_LENGTH];
-    int bytes_read = -1;
+    bytes_read = -1;
     do {
       bytes_read++;
       if (bytes_read >= MAP_LENGTH - 1)
         break;
-      result = read(fd, buffer + bytes_read, 1);
-      if (result < 1) break;
+      bytes_read = read(fd, buffer + bytes_read, 1);
+      if (bytes_read < 1) break;
     } while (buffer[bytes_read] != '\n');
     buffer[bytes_read] = 0;
     // Ignore mappings that are not executable.
@@ -182,13 +182,13 @@ VirtualMemory::VirtualMemory(size_t size
 
 VirtualMemory::VirtualMemory(size_t size, size_t alignment)
     : address_(NULL), size_(0) {
-  DCHECK(IsAligned(alignment, static_cast<intptr_t>(OS::AllocateAlignment())));
+  DCHECK((alignment % OS::AllocateAlignment()) == 0);
   size_t request_size = RoundUp(size + alignment,
                                 static_cast<intptr_t>(OS::AllocateAlignment()));
   void* reservation = mmap(OS::GetRandomMmapAddr(),
                            request_size,
                            PROT_NONE,
-                           MAP_PRIVATE | MAP_ANON | MAP_NORESERVE,
+                           MAP_PRIVATE | MAP_ANON,
                            kMmapFd,
                            kMmapFdOffset);
   if (reservation == MAP_FAILED) return;
@@ -260,7 +260,7 @@ void* VirtualMemory::ReserveRegion(size_
   void* result = mmap(OS::GetRandomMmapAddr(),
                       size,
                       PROT_NONE,
-                      MAP_PRIVATE | MAP_ANON | MAP_NORESERVE,
+                      MAP_PRIVATE | MAP_ANON,
                       kMmapFd,
                       kMmapFdOffset);
 
@@ -288,7 +288,7 @@ bool VirtualMemory::UncommitRegion(void*
   return mmap(base,
               size,
               PROT_NONE,
-              MAP_PRIVATE | MAP_ANON | MAP_NORESERVE | MAP_FIXED,
+              MAP_PRIVATE | MAP_ANON | MAP_FIXED,
               kMmapFd,
               kMmapFdOffset) != MAP_FAILED;
 }
