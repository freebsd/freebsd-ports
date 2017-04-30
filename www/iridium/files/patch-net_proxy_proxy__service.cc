--- net/proxy/proxy_service.cc.orig	2017-04-19 19:06:36 UTC
+++ net/proxy/proxy_service.cc
@@ -49,7 +49,7 @@
 #elif defined(OS_MACOSX)
 #include "net/proxy/proxy_config_service_mac.h"
 #include "net/proxy/proxy_resolver_mac.h"
-#elif defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#elif (defined(OS_LINUX) && !defined(OS_CHROMEOS)) || defined(OS_FREEBSD)
 #include "net/proxy/proxy_config_service_linux.h"
 #elif defined(OS_ANDROID)
 #include "net/proxy/proxy_config_service_android.h"
@@ -1520,7 +1520,7 @@ ProxyService::CreateSystemProxyConfigSer
              << "profile_io_data.cc::CreateProxyConfigService and this should "
              << "be used only for examples.";
   return base::WrapUnique(new UnsetProxyConfigService);
-#elif defined(OS_LINUX)
+#elif defined(OS_LINUX) || defined(OS_BSD)
   std::unique_ptr<ProxyConfigServiceLinux> linux_config_service(
       new ProxyConfigServiceLinux());
 
