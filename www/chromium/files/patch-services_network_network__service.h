--- services/network/network_service.h.orig	2018-12-28 15:42:09.726485000 +0100
+++ services/network/network_service.h	2018-12-28 15:43:21.875987000 +0100
@@ -148,7 +148,7 @@
       mojom::NetworkService::GetTotalNetworkUsagesCallback callback) override;
   void UpdateSignedTreeHead(const net::ct::SignedTreeHead& sth) override;
   void UpdateCRLSet(base::span<const uint8_t> crl_set) override;
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if (defined(OS_LINUX) && !defined(OS_CHROMEOS)) || defined(OS_BSD)
   void SetCryptConfig(mojom::CryptConfigPtr crypt_config) override;
 #endif
 #if defined(OS_MACOSX) && !defined(OS_IOS)
