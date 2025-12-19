--- src/3rdparty/chromium/components/os_crypt/sync/os_crypt.h.orig	2025-08-15 18:30:00 UTC
+++ src/3rdparty/chromium/components/os_crypt/sync/os_crypt.h
@@ -16,7 +16,7 @@
 #include "build/chromecast_buildflags.h"
 #include "crypto/subtle_passkey.h"
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 class KeyStorageLinux;
 #endif  // BUILDFLAG(IS_LINUX)
 
@@ -32,7 +32,7 @@ namespace OSCrypt {
 // Temporary interface due to OSCrypt refactor. See OSCryptImpl for descriptions
 // of what each function does.
 namespace OSCrypt {
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 COMPONENT_EXPORT(OS_CRYPT)
 void SetConfig(std::unique_ptr<os_crypt::Config> config);
 #endif  // BUILDFLAG(IS_LINUX)
@@ -77,7 +77,7 @@ COMPONENT_EXPORT(OS_CRYPT) void ResetStateForTesting()
 COMPONENT_EXPORT(OS_CRYPT) void SetLegacyEncryptionForTesting(bool legacy);
 COMPONENT_EXPORT(OS_CRYPT) void ResetStateForTesting();
 #endif  // BUILDFLAG(IS_WIN)
-#if (BUILDFLAG(IS_LINUX) && !BUILDFLAG(IS_CASTOS))
+#if (BUILDFLAG(IS_LINUX) && !BUILDFLAG(IS_CASTOS)) || BUILDFLAG(IS_BSD)
 COMPONENT_EXPORT(OS_CRYPT)
 void UseMockKeyStorageForTesting(
     base::OnceCallback<std::unique_ptr<KeyStorageLinux>()>
@@ -86,7 +86,7 @@ void SetEncryptionPasswordForTesting(const std::string
 COMPONENT_EXPORT(OS_CRYPT)
 void SetEncryptionPasswordForTesting(const std::string& password);
 #endif  // (BUILDFLAG(IS_LINUX) && !BUILDFLAG(IS_CASTOS))
-#if BUILDFLAG(IS_POSIX) && !BUILDFLAG(IS_APPLE) &&         \
+#if BUILDFLAG(IS_POSIX) && !BUILDFLAG(IS_APPLE) && !BUILDFLAG(IS_BSD) && \
         !(BUILDFLAG(IS_LINUX) && !BUILDFLAG(IS_CASTOS)) || \
     BUILDFLAG(IS_FUCHSIA)
 COMPONENT_EXPORT(OS_CRYPT)
@@ -111,7 +111,7 @@ class COMPONENT_EXPORT(OS_CRYPT) OSCryptImpl {
   // Returns singleton instance of OSCryptImpl.
   static OSCryptImpl* GetInstance();
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // Set the configuration of OSCryptImpl.
   // This method, or SetRawEncryptionKey(), must be called before using
   // EncryptString() and DecryptString().
@@ -203,7 +203,7 @@ class COMPONENT_EXPORT(OS_CRYPT) OSCryptImpl {
   void ResetStateForTesting();
 #endif
 
-#if (BUILDFLAG(IS_LINUX) && !BUILDFLAG(IS_CASTOS))
+#if (BUILDFLAG(IS_LINUX) && !BUILDFLAG(IS_CASTOS)) || BUILDFLAG(IS_BSD)
   // For unit testing purposes, inject methods to be used.
   // |storage_provider_factory| provides the desired |KeyStorage|
   // implementation. If the provider returns |nullptr|, a hardcoded password
@@ -227,13 +227,13 @@ class COMPONENT_EXPORT(OS_CRYPT) OSCryptImpl {
   bool DeriveKey();
 #endif  // BUILDFLAG(IS_APPLE)
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_APPLE)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_APPLE) || BUILDFLAG(IS_BSD)
   // This lock is used to make the GetEncryptionKey and
   // GetRawEncryptionKey methods thread-safe.
   static base::Lock& GetLock();
 #endif  // BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_APPLE)
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   static constexpr size_t kDerivedKeyBytes = 16;
 
   crypto::SubtlePassKey MakeCryptoPassKey();
