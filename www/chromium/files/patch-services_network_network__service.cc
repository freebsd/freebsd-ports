--- services/network/network_service.cc.orig	2020-11-13 06:36:46 UTC
+++ services/network/network_service.cc
@@ -70,7 +70,7 @@
 #include "third_party/boringssl/src/include/openssl/cpu.h"
 #endif
 
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS) && !BUILDFLAG(IS_CHROMECAST)
+#if (defined(OS_LINUX) || defined(OS_BSD)) && !defined(OS_CHROMEOS) && !BUILDFLAG(IS_CHROMECAST)
 #include "components/os_crypt/key_storage_config_linux.h"
 #endif
 
@@ -670,7 +670,7 @@ void NetworkService::OnCertDBChanged() {
   net::CertDatabase::GetInstance()->NotifyObserversCertDBChanged();
 }
 
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if (defined(OS_LINUX) && !defined(OS_CHROMEOS)) || defined(OS_BSD)
 void NetworkService::SetCryptConfig(mojom::CryptConfigPtr crypt_config) {
 #if !BUILDFLAG(IS_CHROMECAST)
   DCHECK(!os_crypt_config_set_);
