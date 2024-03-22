--- chrome/browser/webauthn/chrome_authenticator_request_delegate.cc.orig	2024-03-22 08:19:40 UTC
+++ chrome/browser/webauthn/chrome_authenticator_request_delegate.cc
@@ -805,7 +805,7 @@ void ChromeAuthenticatorRequestDelegate::ConfigureDisc
     g_observer->ConfiguringCable(request_type);
   }
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // No caBLEv1 on Linux. It tends to crash bluez.
   if (base::Contains(pairings_from_extension,
                      device::CableDiscoveryData::Version::V1,
