--- headless/lib/browser/headless_content_browser_client.cc.orig	2025-09-11 13:19:19 UTC
+++ headless/lib/browser/headless_content_browser_client.cc
@@ -59,7 +59,7 @@
 #include "content/public/common/content_descriptors.h"
 #endif  // BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
 
-#if (BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX)) && defined(HEADLESS_USE_PREFS)
+#if (BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)) && defined(HEADLESS_USE_PREFS)
 #include "components/os_crypt/sync/os_crypt.h"  // nogncheck
 #include "content/public/browser/network_service_util.h"
 #endif
@@ -557,7 +557,7 @@ void HeadlessContentBrowserClient::HandleExplicitlyAll
 
 void HeadlessContentBrowserClient::SetEncryptionKey(
     ::network::mojom::NetworkService* network_service) {
-#if (BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX)) && defined(HEADLESS_USE_PREFS)
+#if (BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)) && defined(HEADLESS_USE_PREFS)
   // The OSCrypt keys are process bound, so if network service is out of
   // process, send it the required key if it is available.
   if (content::IsOutOfProcessNetworkService()
