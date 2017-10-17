--- components/os_crypt/os_crypt.h.orig	2017-09-05 21:05:17.000000000 +0200
+++ components/os_crypt/os_crypt.h	2017-09-06 19:12:09.251431000 +0200
@@ -14,9 +14,9 @@
 #include "base/strings/string16.h"
 #include "build/build_config.h"
 
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS) && defined(UNIT_TEST)
+#if (defined(OS_LINUX) || defined(OS_BSD)) && !defined(OS_CHROMEOS) && defined(UNIT_TEST)
 class KeyStorageLinux;
-#endif  // defined(OS_LINUX) && !defined(OS_CHROMEOS) && defined(UNIT_TEST)
+#endif  // (defined(OS_LINUX) || defined(OS_BSD)) && !defined(OS_CHROMEOS) && defined(UNIT_TEST)
 
 namespace os_crypt {
 struct Config;
@@ -28,13 +28,13 @@
 // true for Linux, if a password management tool is available.
 class OSCrypt {
  public:
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if (defined(OS_LINUX) || defined(OS_BSD)) && !defined(OS_CHROMEOS)
   // Set the configuration of OSCrypt.
   static void SetConfig(std::unique_ptr<os_crypt::Config> config);
 
   // Returns true iff the real secret key (not hardcoded one) is available.
   static bool IsEncryptionAvailable();
-#endif  // defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#endif  // (defined(OS_LINUX) || defined(OS_BSD)) && !defined(OS_CHROMEOS)
 
   // Encrypt a string16. The output (second argument) is really an array of
   // bytes, but we're passing it back as a std::string.
@@ -67,7 +67,7 @@
   DISALLOW_IMPLICIT_CONSTRUCTORS(OSCrypt);
 };
 
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS) && defined(UNIT_TEST)
+#if (defined(OS_LINUX) || defined(OS_BSD)) && !defined(OS_CHROMEOS) && defined(UNIT_TEST)
 // For unit testing purposes, inject methods to be used.
 // |get_key_storage_mock| provides the desired |KeyStorage| implementation.
 // If the provider returns |nullptr|, a hardcoded password will be used.
@@ -80,6 +80,6 @@
 // Clears any caching and most lazy initialisations performed by the production
 // code. Should be used after any test which required a password.
 void ClearCacheForTesting();
-#endif  // defined(OS_LINUX) && !defined(OS_CHROMEOS) && defined(UNIT_TEST)
+#endif  // (defined(OS_LINUX) || defined(OS_BSD)) && !defined(OS_CHROMEOS) && defined(UNIT_TEST)
 
 #endif  // COMPONENTS_OS_CRYPT_OS_CRYPT_H_
