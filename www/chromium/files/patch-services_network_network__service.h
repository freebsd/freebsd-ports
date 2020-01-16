--- services/network/network_service.h.orig	2019-12-16 21:51:27 UTC
+++ services/network/network_service.h
@@ -143,7 +143,7 @@ class COMPONENT_EXPORT(NETWORK_SERVICE) NetworkService
       mojom::NetworkService::GetNetworkListCallback callback) override;
   void UpdateCRLSet(base::span<const uint8_t> crl_set) override;
   void OnCertDBChanged() override;
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if (defined(OS_LINUX) && !defined(OS_CHROMEOS)) || defined(OS_BSD)
   void SetCryptConfig(mojom::CryptConfigPtr crypt_config) override;
 #endif
 #if defined(OS_MACOSX) && !defined(OS_IOS)
