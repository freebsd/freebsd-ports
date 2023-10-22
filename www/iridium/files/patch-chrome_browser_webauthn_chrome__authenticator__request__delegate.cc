--- chrome/browser/webauthn/chrome_authenticator_request_delegate.cc.orig	2023-11-22 14:00:11 UTC
+++ chrome/browser/webauthn/chrome_authenticator_request_delegate.cc
@@ -672,7 +672,7 @@ void ChromeAuthenticatorRequestDelegate::ConfigureDisc
     g_observer->ConfiguringCable(request_type);
   }
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // No caBLEv1 on Linux. It tends to crash bluez.
   if (base::Contains(pairings_from_extension,
                      device::CableDiscoveryData::Version::V1,
@@ -879,7 +879,7 @@ void ChromeAuthenticatorRequestDelegate::OnTransportAv
     device::FidoRequestHandlerBase::TransportAvailabilityInfo data) {
   if (base::FeatureList::IsEnabled(device::kWebAuthnFilterGooglePasskeys) &&
       dialog_model()->relying_party_id() == kGoogleRpId &&
-      std::ranges::any_of(data.recognized_credentials,
+      base::ranges::any_of(data.recognized_credentials,
                           IsCredentialFromPlatformAuthenticator)) {
     // Regrettably, Chrome will create webauthn credentials for things other
     // than authentication (e.g. credit card autofill auth) under the rp id
