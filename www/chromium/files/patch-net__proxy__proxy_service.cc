--- net/proxy/proxy_service.cc.orig	2011-05-06 12:02:55.000000000 +0300
+++ net/proxy/proxy_service.cc	2011-06-05 19:34:18.920164573 +0300
@@ -31,7 +31,7 @@
 #elif defined(OS_MACOSX)
 #include "net/proxy/proxy_config_service_mac.h"
 #include "net/proxy/proxy_resolver_mac.h"
-#elif defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#elif (defined(OS_LINUX) || defined(OS_FREEBSD)) && !defined(OS_CHROMEOS)
 #include "net/proxy/proxy_config_service_linux.h"
 #endif
 
@@ -807,7 +807,7 @@
   NOTREACHED() << "ProxyConfigService for ChromeOS should be created in "
                << "profile_io_data.cc::CreateProxyConfigService.";
   return NULL;
-#elif defined(OS_LINUX)
+#elif defined(OS_LINUX) || defined(OS_FREEBSD)
   ProxyConfigServiceLinux* linux_config_service =
       new ProxyConfigServiceLinux();
 
