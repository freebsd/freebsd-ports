--- net/proxy/proxy_service.cc.orig	2011-04-26 11:01:15.000000000 +0300
+++ net/proxy/proxy_service.cc	2011-05-03 20:34:48.665149760 +0300
@@ -25,7 +25,7 @@
 #elif defined(OS_MACOSX)
 #include "net/proxy/proxy_config_service_mac.h"
 #include "net/proxy/proxy_resolver_mac.h"
-#elif defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#elif (defined(OS_LINUX) || defined(OS_FREEBSD)) && !defined(OS_CHROMEOS)
 #include "net/proxy/proxy_config_service_linux.h"
 #endif
 #include "net/proxy/proxy_resolver.h"
@@ -124,6 +124,16 @@
   }
 };
 
+// ProxyConfigService implementation that does nothing.
+class ProxyConfigServiceNull : public ProxyConfigService {
+public:
+  ProxyConfigServiceNull() {}
+  virtual void AddObserver(Observer* observer) {}
+  virtual void RemoveObserver(Observer* observer) {}
+  virtual bool GetLatestProxyConfig(ProxyConfig* config) { return true; }
+  virtual void OnLazyPoll() {}
+};
+
 // ProxyResolver that simulates a PAC script which returns
 // |pac_string| for every single URL.
 class ProxyResolverFromPacString : public ProxyResolver {
@@ -795,7 +805,7 @@
   NOTREACHED() << "ProxyConfigService for ChromeOS should be created in "
                << "chrome_url_request_context.cc::CreateProxyConfigService.";
   return NULL;
-#elif defined(OS_LINUX)
+#elif defined(OS_LINUX) || defined(OS_FREEBSD)
   ProxyConfigServiceLinux* linux_config_service
       = new ProxyConfigServiceLinux();
 
