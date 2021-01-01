--- net/proxy_resolution/proxy_resolution_service.cc.orig	2020-02-03 21:52:49 UTC
+++ net/proxy_resolution/proxy_resolution_service.cc
@@ -49,7 +49,7 @@
 #elif defined(OS_MACOSX)
 #include "net/proxy_resolution/proxy_config_service_mac.h"
 #include "net/proxy_resolution/proxy_resolver_mac.h"
-#elif defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#elif (defined(OS_BSD) || defined(OS_LINUX)) && !defined(OS_CHROMEOS)
 #include "net/proxy_resolution/proxy_config_service_linux.h"
 #elif defined(OS_ANDROID)
 #include "net/proxy_resolution/proxy_config_service_android.h"
@@ -63,7 +63,7 @@ namespace net {
 namespace {
 
 #if defined(OS_WIN) || defined(OS_IOS) || defined(OS_MACOSX) || \
-    (defined(OS_LINUX) && !defined(OS_CHROMEOS))
+    ((defined(OS_BSD) || defined(OS_LINUX)) && !defined(OS_CHROMEOS))
 constexpr net::NetworkTrafficAnnotationTag kSystemProxyConfigTrafficAnnotation =
     net::DefineNetworkTrafficAnnotation("proxy_config_system", R"(
       semantics {
@@ -1556,7 +1556,7 @@ ProxyResolutionService::CreateSystemProxyConfigService
              << "profile_io_data.cc::CreateProxyConfigService and this should "
              << "be used only for examples.";
   return std::make_unique<UnsetProxyConfigService>();
-#elif defined(OS_LINUX)
+#elif defined(OS_LINUX) || defined(OS_BSD)
   std::unique_ptr<ProxyConfigServiceLinux> linux_config_service(
       new ProxyConfigServiceLinux());
 
