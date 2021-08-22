--- services/network/network_context.cc.orig	2021-07-19 18:45:20 UTC
+++ services/network/network_context.cc
@@ -2333,7 +2333,7 @@ NetworkContext::MakeSessionCleanupCookieStore() const 
 
   net::CookieCryptoDelegate* crypto_delegate = nullptr;
   if (params_->enable_encrypted_cookies) {
-#if (defined(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)) && \
+#if (defined(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS) || defined(OS_BSD)) && \
     !BUILDFLAG(IS_CHROMECAST)
     DCHECK(network_service_->os_crypt_config_set())
         << "NetworkService::SetCryptConfig must be called before creating a "
