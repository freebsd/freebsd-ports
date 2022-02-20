--- net/proxy_resolution/configured_proxy_resolution_service.cc.orig	2022-02-07 13:39:41 UTC
+++ net/proxy_resolution/configured_proxy_resolution_service.cc
@@ -52,7 +52,7 @@
 #elif defined(OS_MAC)
 #include "net/proxy_resolution/proxy_config_service_mac.h"
 #include "net/proxy_resolution/proxy_resolver_mac.h"
-#elif defined(OS_LINUX)
+#elif defined(OS_LINUX) || defined(OS_BSD)
 #include "net/proxy_resolution/proxy_config_service_linux.h"
 #elif defined(OS_ANDROID)
 #include "net/proxy_resolution/proxy_config_service_android.h"
@@ -64,7 +64,7 @@ namespace net {
 
 namespace {
 
-#if defined(OS_WIN) || defined(OS_APPLE) || defined(OS_LINUX)
+#if defined(OS_WIN) || defined(OS_APPLE) || defined(OS_LINUX) || defined(OS_BSD)
 constexpr net::NetworkTrafficAnnotationTag kSystemProxyConfigTrafficAnnotation =
     net::DefineNetworkTrafficAnnotation("proxy_config_system", R"(
       semantics {
@@ -1422,7 +1422,7 @@ ConfiguredProxyResolutionService::CreateSystemProxyCon
              << "profile_io_data.cc::CreateProxyConfigService and this should "
              << "be used only for examples.";
   return std::make_unique<UnsetProxyConfigService>();
-#elif defined(OS_LINUX)
+#elif defined(OS_LINUX) || defined(OS_BSD)
   std::unique_ptr<ProxyConfigServiceLinux> linux_config_service(
       new ProxyConfigServiceLinux());
 
