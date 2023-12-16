--- src/3rdparty/chromium/components/os_crypt/keyring_util_linux.cc.orig	2022-04-21 18:48:31 UTC
+++ src/3rdparty/chromium/components/os_crypt/keyring_util_linux.cc
@@ -68,12 +68,12 @@ bool GnomeKeyringLoader::LoadGnomeKeyring() {
   if (keyring_loaded)
     return true;
 
-  void* handle = dlopen("libgnome-keyring.so.0", RTLD_NOW | RTLD_GLOBAL);
+  void* handle = dlopen("libgnome-keyring.so", RTLD_NOW | RTLD_GLOBAL);
   if (!handle) {
     // We wanted to use GNOME Keyring, but we couldn't load it. Warn, because
     // either the user asked for this, or we autodetected it incorrectly. (Or
     // the system has broken libraries, which is also good to warn about.)
-    LOG(WARNING) << "Could not load libgnome-keyring.so.0: " << dlerror();
+    LOG(WARNING) << "Could not load libgnome-keyring.so: " << dlerror();
     return false;
   }
 
