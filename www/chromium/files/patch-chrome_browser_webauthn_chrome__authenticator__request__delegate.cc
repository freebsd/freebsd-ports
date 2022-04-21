--- chrome/browser/webauthn/chrome_authenticator_request_delegate.cc.orig	2022-04-21 18:48:31 UTC
+++ chrome/browser/webauthn/chrome_authenticator_request_delegate.cc
@@ -869,7 +869,7 @@ bool ChromeAuthenticatorRequestDelegate::ShouldPermitC
   // TODO(crbug.com/1052397): Revisit the macro expression once build flag
   // switch of lacros-chrome is complete. If updating this, also update
   // kWebAuthCableServerLink.
-#if BUILDFLAG(IS_CHROMEOS_LACROS) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_CHROMEOS_LACROS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 
   // caBLEv1 is disabled on these platforms. It never launched on them because
   // it causes problems in bluez. Rather than disabling caBLE completely, which
