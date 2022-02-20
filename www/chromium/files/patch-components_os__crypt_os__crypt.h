--- components/os_crypt/os_crypt.h.orig	2022-02-07 13:39:41 UTC
+++ components/os_crypt/os_crypt.h
@@ -16,7 +16,7 @@
 
 // TODO(crbug.com/1052397): Revisit the macro expression once build flag switch
 // of lacros-chrome is complete.
-#if defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)
+#if defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS) || defined(OS_BSD)
 class KeyStorageLinux;
 #endif  // defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)
 
@@ -41,7 +41,7 @@ class OSCrypt {
 
 // TODO(crbug.com/1052397): Revisit the macro expression once build flag switch
 // of lacros-chrome is complete.
-#if defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)
+#if defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS) || defined(OS_BSD)
   // Set the configuration of OSCrypt.
   static COMPONENT_EXPORT(OS_CRYPT) void SetConfig(
       std::unique_ptr<os_crypt::Config> config);
@@ -49,7 +49,7 @@ class OSCrypt {
 
 // TODO(crbug.com/1052397): Revisit the macro expression once build flag switch
 // of lacros-chrome is complete.
-#if defined(OS_APPLE) || defined(OS_WIN) || \
+#if defined(OS_APPLE) || defined(OS_WIN) || defined(OS_BSD) || \
     (defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS))
   // On Linux returns true iff the real secret key (not hardcoded one) is
   // available. On MacOS returns true if Keychain is available (for mock
@@ -141,7 +141,7 @@ class OSCrypt {
 
 // TODO(crbug.com/1052397): Revisit the macro expression once build flag switch
 // of lacros-chrome is complete.
-#if defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)
+#if defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS) || defined(OS_BSD)
 // For unit testing purposes, inject methods to be used.
 // |get_key_storage_mock| provides the desired |KeyStorage| implementation.
 // If the provider returns |nullptr|, a hardcoded password will be used.
