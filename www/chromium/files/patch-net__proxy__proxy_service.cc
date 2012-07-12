--- net/proxy/proxy_service.cc.orig	2012-05-30 10:01:26.000000000 +0300
+++ net/proxy/proxy_service.cc	2012-06-05 22:28:13.000000000 +0300
@@ -38,7 +38,7 @@
 #elif defined(OS_MACOSX)
 #include "net/proxy/proxy_config_service_mac.h"
 #include "net/proxy/proxy_resolver_mac.h"
-#elif defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#elif (defined(OS_LINUX) || defined(OS_FREEBSD)) && !defined(OS_CHROMEOS)
 #include "net/proxy/proxy_config_service_linux.h"
 #endif
 
@@ -1429,7 +1429,7 @@
              << "profile_io_data.cc::CreateProxyConfigService and this should "
              << "be used only for examples.";
   return new UnsetProxyConfigService;
-#elif defined(OS_LINUX)
+#elif defined(OS_LINUX) || defined(OS_FREEBSD)
   ProxyConfigServiceLinux* linux_config_service =
       new ProxyConfigServiceLinux();
 
