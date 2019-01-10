--- services/network/network_context.cc.orig	2019-01-09 11:56:44.681236000 +0100
+++ services/network/network_context.cc	2019-01-09 12:00:05.840566000 +0100
@@ -110,7 +110,7 @@
 #endif  // defined(USE_NSS_CERTS)
 
 #if defined(OS_ANDROID) || defined(OS_FUCHSIA) || \
-    (defined(OS_LINUX) && !defined(OS_CHROMEOS)) || defined(OS_MACOSX)
+    ((defined(OS_BSD) || defined(OS_LINUX)) && !defined(OS_CHROMEOS)) || defined(OS_MACOSX)
 #include "net/cert/cert_net_fetcher.h"
 #include "net/cert_net/cert_net_fetcher_impl.h"
 #endif
@@ -543,7 +543,7 @@
 #endif
 
 #if defined(OS_ANDROID) || defined(OS_FUCHSIA) || \
-    (defined(OS_LINUX) && !defined(OS_CHROMEOS)) || defined(OS_MACOSX)
+    ((defined(OS_BSD) || defined(OS_LINUX)) && !defined(OS_CHROMEOS)) || defined(OS_MACOSX)
     net::ShutdownGlobalCertNetFetcher();
 #endif
   }
@@ -1367,7 +1367,7 @@
 
     net::CookieCryptoDelegate* crypto_delegate = nullptr;
     if (params_->enable_encrypted_cookies) {
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS) && !defined(IS_CHROMECAST)
+#if (defined(OS_BSD) || defined(OS_LINUX)) && !defined(OS_CHROMEOS) && !defined(IS_CHROMECAST)
       DCHECK(network_service_->os_crypt_config_set())
           << "NetworkService::SetCryptConfig must be called before creating a "
              "NetworkContext with encrypted cookies.";
@@ -1654,7 +1654,7 @@
     net::SetURLRequestContextForNSSHttpIO(result.url_request_context.get());
 #endif
 #if defined(OS_ANDROID) || defined(OS_FUCHSIA) || \
-    (defined(OS_LINUX) && !defined(OS_CHROMEOS)) || defined(OS_MACOSX)
+    ((defined(OS_BSD) || defined(OS_LINUX)) && !defined(OS_CHROMEOS)) || defined(OS_MACOSX)
     net::SetGlobalCertNetFetcher(
         net::CreateCertNetFetcher(result.url_request_context.get()));
 #endif
