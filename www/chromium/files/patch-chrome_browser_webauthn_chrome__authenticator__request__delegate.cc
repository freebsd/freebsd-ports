--- chrome/browser/webauthn/chrome_authenticator_request_delegate.cc.orig	2024-05-21 18:07:39 UTC
+++ chrome/browser/webauthn/chrome_authenticator_request_delegate.cc
@@ -798,7 +798,7 @@ void ChromeAuthenticatorRequestDelegate::ConfigureDisc
     g_observer->ConfiguringCable(request_type);
   }
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // No caBLEv1 on Linux. It tends to crash bluez.
   if (base::Contains(pairings_from_extension,
                      device::CableDiscoveryData::Version::V1,
