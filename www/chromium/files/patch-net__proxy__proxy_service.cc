--- net/proxy/proxy_service.cc.orig	2011-03-20 22:02:04.206737865 +0200
+++ net/proxy/proxy_service.cc	2011-03-20 22:02:04.398743833 +0200
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
