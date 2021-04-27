--- services/network/network_service.h.orig	2021-04-14 18:41:08 UTC
+++ services/network/network_service.h
@@ -193,7 +193,7 @@ class COMPONENT_EXPORT(NETWORK_SERVICE) NetworkService
       base::span<const uint8_t> crl_set,
       mojom::NetworkService::UpdateCRLSetCallback callback) override;
   void OnCertDBChanged() override;
-#if defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)
+#if defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS) || defined(OS_BSD)
   void SetCryptConfig(mojom::CryptConfigPtr crypt_config) override;
 #endif
 #if defined(OS_WIN) || defined(OS_MAC)
