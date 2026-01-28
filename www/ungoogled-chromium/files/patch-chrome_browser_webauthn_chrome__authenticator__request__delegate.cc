--- chrome/browser/webauthn/chrome_authenticator_request_delegate.cc.orig	2026-01-16 13:40:34 UTC
+++ chrome/browser/webauthn/chrome_authenticator_request_delegate.cc
@@ -548,7 +548,7 @@ void ChromeAuthenticatorRequestDelegate::ConfigureDisc
     g_observer->ConfiguringCable(request_type);
   }
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // No caBLEv1 on Linux. It tends to crash bluez.
   if (base::Contains(pairings_from_extension,
                      device::CableDiscoveryData::Version::V1,
