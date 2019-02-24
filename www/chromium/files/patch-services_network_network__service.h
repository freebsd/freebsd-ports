--- services/network/network_service.h.orig	2019-01-30 02:18:10.000000000 +0100
+++ services/network/network_service.h	2019-02-01 10:39:31.949929000 +0100
@@ -174,7 +174,7 @@
 #endif  // !BUILDFLAG(IS_CT_SUPPORTED)
   void UpdateCRLSet(base::span<const uint8_t> crl_set) override;
   void OnCertDBChanged() override;
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if (defined(OS_LINUX) && !defined(OS_CHROMEOS)) || defined(OS_BSD)
   void SetCryptConfig(mojom::CryptConfigPtr crypt_config) override;
 #endif
 #if defined(OS_MACOSX) && !defined(OS_IOS)
