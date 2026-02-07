--- Libraries/MiKTeX/Core/Utils/unx/unxUtils.cpp.orig	2021-08-06 15:45:04 UTC
+++ Libraries/MiKTeX/Core/Utils/unx/unxUtils.cpp
@@ -26,6 +26,8 @@
 #if defined(__APPLE__)
 #  include <mach-o/dyld.h>
 #endif
+#include <sys/types.h>
+#include <sys/sysctl.h>
 
 #if defined(HAVE_SYS_UTSNAME_H)
 #  include <sys/utsname.h>
@@ -179,6 +181,16 @@ PathName Utils::GetExe()
         }
     }
     return PathName(buf.GetData());
+#elif defined(__FreeBSD__)
+        int mib[4];
+        mib[0] = CTL_KERN;
+        mib[1] = KERN_PROC;
+        mib[2] = KERN_PROC_PATHNAME;
+        mib[3] = -1;
+        char buf[1024];
+        size_t cb = sizeof(buf);
+        sysctl(mib, 4, buf, &cb, NULL, 0);
+    return PathName(buf);
 #else
     return File::ReadSymbolicLink(PathName("/proc/self/exe"));
 #endif
@@ -186,7 +198,7 @@ PathName Utils::GetExe()
 
 string Utils::GetExeName()
 {
-#if defined(__APPLE__)
+#if defined(__APPLE__) || defined (__FreeBSD__)
     return GetExe().GetFileNameWithoutExtension().ToString();
 #else
     ifstream cmdline = File::CreateInputStream(PathName("/proc/self/comm"));
