--- components/os_crypt/os_crypt.h.orig	2022-02-28 16:54:41 UTC
+++ components/os_crypt/os_crypt.h
@@ -14,7 +14,7 @@
 #include "build/build_config.h"
 #include "build/chromecast_buildflags.h"
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 class KeyStorageLinux;
 #endif  // BUILDFLAG(IS_LINUX)
 
@@ -37,7 +37,7 @@ class OSCrypt {
   OSCrypt(const OSCrypt&) = delete;
   OSCrypt& operator=(const OSCrypt&) = delete;
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // Set the configuration of OSCrypt.
   // This method, or SetRawEncryptionKey(), must be called before using
   // EncryptString() and DecryptString().
@@ -149,7 +149,7 @@ class OSCrypt {
   static COMPONENT_EXPORT(OS_CRYPT) void ResetStateForTesting();
 #endif
 
-#if (BUILDFLAG(IS_LINUX) && !BUILDFLAG(IS_CHROMECAST))
+#if ((BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)) && !BUILDFLAG(IS_CHROMECAST))
   // For unit testing purposes, inject methods to be used.
   // |get_key_storage_mock| provides the desired |KeyStorage| implementation.
   // If the provider returns |nullptr|, a hardcoded password will be used.
