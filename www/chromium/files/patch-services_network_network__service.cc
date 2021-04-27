--- services/network/network_service.cc.orig	2021-04-14 18:41:08 UTC
+++ services/network/network_service.cc
@@ -72,7 +72,7 @@
 #include "third_party/boringssl/src/include/openssl/cpu.h"
 #endif
 
-#if (defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)) && \
+#if (defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS) || defined(OS_BSD)) && \
     !BUILDFLAG(IS_CHROMECAST)
 #include "components/os_crypt/key_storage_config_linux.h"
 #endif
@@ -661,7 +661,7 @@ void NetworkService::OnCertDBChanged() {
   net::CertDatabase::GetInstance()->NotifyObserversCertDBChanged();
 }
 
-#if defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)
+#if defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS) || defined(OS_BSD)
 void NetworkService::SetCryptConfig(mojom::CryptConfigPtr crypt_config) {
 #if !BUILDFLAG(IS_CHROMECAST)
   DCHECK(!os_crypt_config_set_);
