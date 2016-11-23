--- net/proxy/proxy_service.cc.orig	2016-07-20 22:03:27.000000000 +0300
+++ net/proxy/proxy_service.cc	2016-08-01 04:25:47.866569000 +0300
@@ -48,7 +48,7 @@
 #elif defined(OS_MACOSX)
 #include "net/proxy/proxy_config_service_mac.h"
 #include "net/proxy/proxy_resolver_mac.h"
-#elif defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#elif (defined(OS_LINUX) && !defined(OS_CHROMEOS)) || defined(OS_FREEBSD)
 #include "net/proxy/proxy_config_service_linux.h"
 #elif defined(OS_ANDROID)
 #include "net/proxy/proxy_config_service_android.h"
@@ -1542,7 +1542,7 @@
              << "profile_io_data.cc::CreateProxyConfigService and this should "
              << "be used only for examples.";
   return base::WrapUnique(new UnsetProxyConfigService);
-#elif defined(OS_LINUX)
+#elif defined(OS_LINUX) || defined(OS_BSD)
   std::unique_ptr<ProxyConfigServiceLinux> linux_config_service(
       new ProxyConfigServiceLinux());

