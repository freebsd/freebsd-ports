--- chrome/browser/webauthn/chrome_authenticator_request_delegate.cc.orig	2026-05-07 17:02:56 UTC
+++ chrome/browser/webauthn/chrome_authenticator_request_delegate.cc
@@ -542,7 +542,7 @@ void ChromeAuthenticatorRequestDelegate::ConfigureDisc
     g_observer->ConfiguringCable(request_type);
   }
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // No caBLEv1 on Linux. It tends to crash bluez.
   if (std::ranges::contains(pairings_from_extension,
                             device::CableDiscoveryData::Version::V1,
