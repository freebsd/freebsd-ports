--- chrome/browser/webauthn/unexportable_key_utils.cc.orig	2025-04-04 08:52:13 UTC
+++ chrome/browser/webauthn/unexportable_key_utils.cc
@@ -34,7 +34,7 @@ GetWebAuthnUnexportableKeyProvider() {
   // If there is a scoped UnexportableKeyProvider configured, we always use
   // that so that tests can still override the key provider.
   const bool use_software_provider =
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_ASH)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_ASH) || BUILDFLAG(IS_BSD)
       !crypto::internal::HasScopedUnexportableKeyProvider();
 #else
       false;
