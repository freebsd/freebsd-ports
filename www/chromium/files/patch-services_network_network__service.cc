--- services/network/network_service.cc.orig	2019-04-30 22:22:56 UTC
+++ services/network/network_service.cc
@@ -61,7 +61,7 @@
 #include "third_party/boringssl/src/include/openssl/cpu.h"
 #endif
 
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS) && !defined(IS_CHROMECAST)
+#if (defined(OS_LINUX) && !defined(OS_CHROMEOS) && !defined(IS_CHROMECAST)) || defined(OS_BSD)
 #include "components/os_crypt/key_storage_config_linux.h"
 #endif
 
@@ -620,7 +620,7 @@ void NetworkService::OnCertDBChanged() {
   net::CertDatabase::GetInstance()->NotifyObserversCertDBChanged();
 }
 
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if (defined(OS_LINUX) && !defined(OS_CHROMEOS)) || defined(OS_BSD)
 void NetworkService::SetCryptConfig(mojom::CryptConfigPtr crypt_config) {
 #if !defined(IS_CHROMECAST)
   DCHECK(!os_crypt_config_set_);
