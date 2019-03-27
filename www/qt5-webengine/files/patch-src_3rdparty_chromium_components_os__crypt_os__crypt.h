--- src/3rdparty/chromium/components/os_crypt/os_crypt.h.orig	2018-11-13 18:25:11 UTC
+++ src/3rdparty/chromium/components/os_crypt/os_crypt.h
@@ -14,7 +14,7 @@
 #include "base/strings/string16.h"
 #include "build/build_config.h"
 
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS) && defined(UNIT_TEST)
+#if (defined(OS_LINUX) || defined(OS_BSD)) && !defined(OS_CHROMEOS) && defined(UNIT_TEST)
 class KeyStorageLinux;
 #endif  // defined(OS_LINUX) && !defined(OS_CHROMEOS) && defined(UNIT_TEST)
 
@@ -28,7 +28,7 @@ struct Config;
 // true for Linux, if a password management tool is available.
 class OSCrypt {
  public:
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if (defined(OS_LINUX) || defined(OS_BSD)) && !defined(OS_CHROMEOS)
   // Set the configuration of OSCrypt.
   static void SetConfig(std::unique_ptr<os_crypt::Config> config);
 
@@ -67,7 +67,7 @@ class OSCrypt {
   DISALLOW_IMPLICIT_CONSTRUCTORS(OSCrypt);
 };
 
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS) && defined(UNIT_TEST)
+#if (defined(OS_LINUX) || defined(OS_BSD)) && !defined(OS_CHROMEOS) && defined(UNIT_TEST)
 // For unit testing purposes, inject methods to be used.
 // |get_key_storage_mock| provides the desired |KeyStorage| implementation.
 // If the provider returns |nullptr|, a hardcoded password will be used.
@@ -81,6 +81,6 @@ void UseMockKeyStorageForTesting(
 // Clears any caching and most lazy initialisations performed by the production
 // code. Should be used after any test which required a password.
 void ClearCacheForTesting();
-#endif  // defined(OS_LINUX) && !defined(OS_CHROMEOS) && defined(UNIT_TEST)
+#endif  // (defined(OS_LINUX) || defined(OS_BSD)) && !defined(OS_CHROMEOS) && defined(UNIT_TEST)
 
 #endif  // COMPONENTS_OS_CRYPT_OS_CRYPT_H_
