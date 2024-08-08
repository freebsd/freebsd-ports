--- chrome/browser/webauthn/chrome_authenticator_request_delegate.cc.orig	2024-07-30 11:12:21 UTC
+++ chrome/browser/webauthn/chrome_authenticator_request_delegate.cc
@@ -972,7 +972,7 @@ void ChromeAuthenticatorRequestDelegate::ConfigureDisc
     g_observer->ConfiguringCable(request_type);
   }
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // No caBLEv1 on Linux. It tends to crash bluez.
   if (base::Contains(pairings_from_extension,
                      device::CableDiscoveryData::Version::V1,
