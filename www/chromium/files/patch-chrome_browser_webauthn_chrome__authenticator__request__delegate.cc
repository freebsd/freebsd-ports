--- chrome/browser/webauthn/chrome_authenticator_request_delegate.cc.orig	2024-10-22 08:31:56 UTC
+++ chrome/browser/webauthn/chrome_authenticator_request_delegate.cc
@@ -1143,7 +1143,7 @@ void ChromeAuthenticatorRequestDelegate::ConfigureDisc
     g_observer->ConfiguringCable(request_type);
   }
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // No caBLEv1 on Linux. It tends to crash bluez.
   if (base::Contains(pairings_from_extension,
                      device::CableDiscoveryData::Version::V1,
