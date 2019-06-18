--- services/network/network_service.h.orig	2019-03-11 22:01:01 UTC
+++ services/network/network_service.h
@@ -186,7 +186,7 @@ class COMPONENT_EXPORT(NETWORK_SERVICE) NetworkService
 #endif  // !BUILDFLAG(IS_CT_SUPPORTED)
   void UpdateCRLSet(base::span<const uint8_t> crl_set) override;
   void OnCertDBChanged() override;
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if (defined(OS_LINUX) && !defined(OS_CHROMEOS)) || defined(OS_BSD)
   void SetCryptConfig(mojom::CryptConfigPtr crypt_config) override;
 #endif
 #if defined(OS_MACOSX) && !defined(OS_IOS)
