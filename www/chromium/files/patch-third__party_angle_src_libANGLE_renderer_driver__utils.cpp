--- third_party/angle/src/libANGLE/renderer/driver_utils.cpp.orig	2021-07-19 18:47:19 UTC
+++ third_party/angle/src/libANGLE/renderer/driver_utils.cpp
@@ -17,7 +17,7 @@
 #    include <sys/system_properties.h>
 #endif
 
-#if defined(ANGLE_PLATFORM_LINUX)
+#if defined(ANGLE_PLATFORM_POSIX)
 #    include <sys/utsname.h>
 #endif
 
@@ -235,7 +235,7 @@ OSVersion GetMacOSVersion()
 }
 #endif
 
-#if defined(ANGLE_PLATFORM_LINUX)
+#if defined(ANGLE_PLATFORM_POSIX)
 bool ParseLinuxOSVersion(const char *version, int *major, int *minor, int *patch)
 {
     errno = 0;  // reset global error flag.
@@ -247,6 +247,14 @@ bool ParseLinuxOSVersion(const char *version, int *maj
     }
 
     *minor = static_cast<int>(strtol(next + 1, &next, 10));
+#if defined(__FreeBSD__)
+    if (next == nullptr || *next != '-' || errno != 0)
+    {
+        return false;
+    }
+
+    *patch = 0;
+#else
     if (next == nullptr || *next != '.' || errno != 0)
     {
         return false;
@@ -257,6 +265,7 @@ bool ParseLinuxOSVersion(const char *version, int *maj
     {
         return false;
     }
+#endif
 
     return true;
 }
@@ -264,7 +273,7 @@ bool ParseLinuxOSVersion(const char *version, int *maj
 
 OSVersion GetLinuxOSVersion()
 {
-#if defined(ANGLE_PLATFORM_LINUX)
+#if defined(ANGLE_PLATFORM_POSIX)
     struct utsname uname_info;
     if (uname(&uname_info) != 0)
     {
