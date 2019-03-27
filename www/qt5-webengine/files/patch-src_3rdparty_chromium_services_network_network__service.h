--- src/3rdparty/chromium/services/network/network_service.h.orig	2018-11-13 18:25:11 UTC
+++ src/3rdparty/chromium/services/network/network_service.h
@@ -133,7 +133,7 @@ class COMPONENT_EXPORT(NETWORK_SERVICE) NetworkService
   void GetTotalNetworkUsages(
       mojom::NetworkService::GetTotalNetworkUsagesCallback callback) override;
   void UpdateSignedTreeHead(const net::ct::SignedTreeHead& sth) override;
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if (defined(OS_LINUX) && !defined(OS_CHROMEOS)) || defined(OS_BSD)
   void SetCryptConfig(mojom::CryptConfigPtr crypt_config) override;
 #endif
 
