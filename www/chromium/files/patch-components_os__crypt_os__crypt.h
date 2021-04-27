--- components/os_crypt/os_crypt.h.orig	2021-04-14 18:40:59 UTC
+++ components/os_crypt/os_crypt.h
@@ -18,9 +18,9 @@
 
 // TODO(crbug.com/1052397): Revisit the macro expression once build flag switch
 // of lacros-chrome is complete.
-#if defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)
+#if defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS) || defined(OS_BSD)
 class KeyStorageLinux;
-#endif  // defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)
+#endif  // defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS) || defined(OS_BSD)
 
 #if defined(OS_WIN) || defined(OS_MAC)
 class PrefRegistrySimple;
@@ -39,16 +39,16 @@ class OSCrypt {
  public:
 // TODO(crbug.com/1052397): Revisit the macro expression once build flag switch
 // of lacros-chrome is complete.
-#if defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)
+#if defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS) || defined(OS_BSD)
   // Set the configuration of OSCrypt.
   static COMPONENT_EXPORT(OS_CRYPT) void SetConfig(
       std::unique_ptr<os_crypt::Config> config);
-#endif  // defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)
+#endif  // defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS) || defined(OS_BSD)
 
 // TODO(crbug.com/1052397): Revisit the macro expression once build flag switch
 // of lacros-chrome is complete.
 #if defined(OS_APPLE) || defined(OS_WIN) || \
-    (defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS))
+    (defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)) || defined(OS_BSD)
   // On Linux returns true iff the real secret key (not hardcoded one) is
   // available. On MacOS returns true if Keychain is available (for mock
   // Keychain it returns true if not using locked Keychain, false if using
@@ -142,7 +142,7 @@ class OSCrypt {
 
 // TODO(crbug.com/1052397): Revisit the macro expression once build flag switch
 // of lacros-chrome is complete.
-#if defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)
+#if defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS) || defined(OS_BSD)
 // For unit testing purposes, inject methods to be used.
 // |get_key_storage_mock| provides the desired |KeyStorage| implementation.
 // If the provider returns |nullptr|, a hardcoded password will be used.
@@ -157,6 +157,6 @@ void UseMockKeyStorageForTesting(
 // Clears any caching and most lazy initialisations performed by the production
 // code. Should be used after any test which required a password.
 COMPONENT_EXPORT(OS_CRYPT) void ClearCacheForTesting();
-#endif  // defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)
+#endif  // defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS) || defined(OS_BSD)
 
 #endif  // COMPONENTS_OS_CRYPT_OS_CRYPT_H_
