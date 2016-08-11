--- net/proxy/proxy_service.cc.orig	2016-05-11 19:02:24 UTC
+++ net/proxy/proxy_service.cc
@@ -47,7 +47,7 @@
 #elif defined(OS_MACOSX)
 #include "net/proxy/proxy_config_service_mac.h"
 #include "net/proxy/proxy_resolver_mac.h"
-#elif defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#elif (defined(OS_LINUX) && !defined(OS_CHROMEOS)) || defined(OS_FREEBSD)
 #include "net/proxy/proxy_config_service_linux.h"
 #elif defined(OS_ANDROID)
 #include "net/proxy/proxy_config_service_android.h"
@@ -1503,7 +1503,7 @@ scoped_ptr<ProxyConfigService> ProxyServ
              << "profile_io_data.cc::CreateProxyConfigService and this should "
              << "be used only for examples.";
   return make_scoped_ptr(new UnsetProxyConfigService);
-#elif defined(OS_LINUX)
+#elif defined(OS_LINUX) || defined(OS_FREEBSD)
   scoped_ptr<ProxyConfigServiceLinux> linux_config_service(
       new ProxyConfigServiceLinux());
 
