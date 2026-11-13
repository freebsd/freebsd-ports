--- chrome/browser/webauthn/unexportable_key_utils.cc.orig	2026-11-11 14:44:17 UTC
+++ chrome/browser/webauthn/unexportable_key_utils.cc
@@ -79,7 +79,7 @@ GetWebAuthnUnexportableKeyProvider() {
   }
 #endif
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   // On Linux, access to the TPM is complex compared to Windows and macOS.
   // There are libraries that _should_ work with a TPM 2.0, but Linux
   // often runs on non-PCs, where TPMs will probably never exist. Thus
