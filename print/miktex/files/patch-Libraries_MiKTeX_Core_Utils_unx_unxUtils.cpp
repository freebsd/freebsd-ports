--- Libraries/MiKTeX/Core/Utils/unx/unxUtils.cpp.orig	2026-05-13 12:29:06 UTC
+++ Libraries/MiKTeX/Core/Utils/unx/unxUtils.cpp
@@ -22,6 +22,8 @@
 #if defined(HAVE_SYS_UTSNAME_H)
 #include <sys/utsname.h>
 #endif
+#include <sys/types.h>
+#include <sys/sysctl.h>
 
 #include <fmt/format.h>
 #include <fmt/ostream.h>
@@ -171,6 +173,16 @@ PathName Utils::GetExe()
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
@@ -178,7 +190,7 @@ string Utils::GetExeName()
 
 string Utils::GetExeName()
 {
-#if defined(__APPLE__)
+#if defined(__APPLE__) || defined (__FreeBSD__)
     return GetExe().GetFileNameWithoutExtension().ToString();
 #else
     ifstream cmdline = File::CreateInputStream(PathName("/proc/self/comm"));
