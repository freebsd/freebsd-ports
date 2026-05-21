Use dlsym to access environ. This avoids undefined references during linking
with -Wl,-no-undefined.

See https://reviews.freebsd.org/D30842

--- src/3rdparty/chromium/base/process/launch_posix.cc.orig	2026-02-26 14:39:03 UTC
+++ src/3rdparty/chromium/base/process/launch_posix.cc
@@ -61,7 +61,9 @@
 #error "macOS should use launch_mac.cc"
 #endif
 
+#if !defined(OS_FREEBSD)
 extern char** environ;
+#endif
 
 namespace base {
 
@@ -82,13 +84,27 @@ char** GetEnvironment() {
 // Get the process's "environment" (i.e. the thing that setenv/getenv
 // work with).
 char** GetEnvironment() {
+#if !defined(OS_FREEBSD)
   return environ;
+#else
+  static char* nullenv = nullptr;
+  char ***environ_p = reinterpret_cast<char***>(dlsym(RTLD_DEFAULT, "environ"));
+  char **environ = environ_p ? *environ_p : &nullenv;
+  return environ;
+#endif
 }
 
 // Set the process's "environment" (i.e. the thing that setenv/getenv
 // work with).
 void SetEnvironment(char** env) {
+#if !defined(OS_FREEBSD)
   environ = env;
+#else
+  char ***environ_p = reinterpret_cast<char***>(dlsym(RTLD_DEFAULT, "environ"));
+  if (!environ_p)
+    return;
+  *environ_p = env;
+#endif
 }
 
 // Set the calling thread's signal mask to new_sigmask and return
