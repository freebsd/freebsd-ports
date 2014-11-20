--- chrome/browser/net/connection_tester.cc.orig	2014-10-10 09:15:30 UTC
+++ chrome/browser/net/connection_tester.cc
@@ -219,7 +219,7 @@
   // Otherwise returns a network error code.
   int CreateSystemProxyConfigService(
       scoped_ptr<net::ProxyConfigService>* config_service) {
-#if defined(OS_LINUX) || defined(OS_OPENBSD)
+#if defined(OS_LINUX) || defined(OS_BSD)
     // TODO(eroman): This is not supported on Linux yet, because of how
     // construction needs ot happen on the UI thread.
     return net::ERR_NOT_IMPLEMENTED;
