--- services/network/network_context.cc.orig	2021-01-18 21:29:02 UTC
+++ services/network/network_context.cc
@@ -2292,7 +2292,7 @@ NetworkContext::MakeSessionCleanupCookieStore() const 
 
   net::CookieCryptoDelegate* crypto_delegate = nullptr;
   if (params_->enable_encrypted_cookies) {
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS) && !BUILDFLAG(IS_CHROMECAST)
+#if (defined(OS_LINUX) && !defined(OS_CHROMEOS) && !BUILDFLAG(IS_CHROMECAST)) || defined(OS_BSD)
     DCHECK(network_service_->os_crypt_config_set())
         << "NetworkService::SetCryptConfig must be called before creating a "
            "NetworkContext with encrypted cookies.";
