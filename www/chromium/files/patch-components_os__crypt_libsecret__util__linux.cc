--- components/os_crypt/libsecret_util_linux.cc.orig	2022-06-17 14:20:10 UTC
+++ components/os_crypt/libsecret_util_linux.cc
@@ -102,13 +102,13 @@ bool LibsecretLoader::LoadLibsecret() {
   if (libsecret_loaded_)
     return true;
 
-  static void* handle = dlopen("libsecret-1.so.0", RTLD_NOW | RTLD_GLOBAL);
+  static void* handle = dlopen("libsecret-1.so", RTLD_NOW | RTLD_GLOBAL);
   if (!handle) {
     // We wanted to use libsecret, but we couldn't load it. Warn, because
     // either the user asked for this, or we autodetected it incorrectly. (Or
     // the system has broken libraries, which is also good to warn about.)
     // TODO(crbug.com/607435): Channel this message to the user-facing log
-    VLOG(1) << "Could not load libsecret-1.so.0: " << dlerror();
+    VLOG(1) << "Could not load libsecret-1.so: " << dlerror();
     return false;
   }
 
