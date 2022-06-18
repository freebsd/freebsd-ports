--- chrome/browser/webauthn/chrome_authenticator_request_delegate.cc.orig	2022-06-17 14:20:10 UTC
+++ chrome/browser/webauthn/chrome_authenticator_request_delegate.cc
@@ -670,7 +670,7 @@ void ChromeAuthenticatorRequestDelegate::ConfigureCabl
 
   // TODO(crbug.com/1052397): Revisit the macro expression once build flag
   // switch of lacros-chrome is complete.
-#if BUILDFLAG(IS_CHROMEOS_LACROS) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_CHROMEOS_LACROS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   if (std::any_of(pairings_from_extension.begin(),
                   pairings_from_extension.end(),
                   [](const device::CableDiscoveryData& v) -> bool {
