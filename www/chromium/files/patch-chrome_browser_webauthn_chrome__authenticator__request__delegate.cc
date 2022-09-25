--- chrome/browser/webauthn/chrome_authenticator_request_delegate.cc.orig	2022-09-24 10:57:32 UTC
+++ chrome/browser/webauthn/chrome_authenticator_request_delegate.cc
@@ -668,7 +668,7 @@ void ChromeAuthenticatorRequestDelegate::ConfigureCabl
     }
   }
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // No caBLEv1 on Linux. It tends to crash bluez.
   if (std::any_of(pairings_from_extension.begin(),
                   pairings_from_extension.end(),
