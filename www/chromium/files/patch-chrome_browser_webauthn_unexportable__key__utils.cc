--- chrome/browser/webauthn/unexportable_key_utils.cc.orig	2025-12-05 10:12:50 UTC
+++ chrome/browser/webauthn/unexportable_key_utils.cc
@@ -42,7 +42,7 @@ GetWebAuthnUnexportableKeyProvider() {
   // If there is a scoped UnexportableKeyProvider configured, we always use
   // that so that tests can still override the key provider.
   const bool use_software_provider =
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
       !crypto::internal::HasScopedUnexportableKeyProvider();
 #else
       false;
