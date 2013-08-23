--- net/proxy/proxy_service.cc.orig	2013-08-09 22:05:31.000000000 +0300
+++ net/proxy/proxy_service.cc	2013-08-19 21:08:08.000000000 +0300
@@ -39,7 +39,7 @@
 #elif defined(OS_MACOSX)
 #include "net/proxy/proxy_config_service_mac.h"
 #include "net/proxy/proxy_resolver_mac.h"
-#elif defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#elif (defined(OS_LINUX) && !defined(OS_CHROMEOS)) || defined(OS_FREEBSD)
 #include "net/proxy/proxy_config_service_linux.h"
 #elif defined(OS_ANDROID)
 #include "net/proxy/proxy_config_service_android.h"
@@ -1347,7 +1347,7 @@
              << "profile_io_data.cc::CreateProxyConfigService and this should "
              << "be used only for examples.";
   return new UnsetProxyConfigService;
-#elif defined(OS_LINUX)
+#elif defined(OS_LINUX) || defined(OS_FREEBSD)
   ProxyConfigServiceLinux* linux_config_service =
       new ProxyConfigServiceLinux();
 
