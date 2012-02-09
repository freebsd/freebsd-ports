--- chrome/browser/net/connection_tester.cc.orig	2012-01-18 11:12:39.000000000 +0200
+++ chrome/browser/net/connection_tester.cc	2012-01-29 15:24:02.000000000 +0200
@@ -212,7 +212,7 @@
   // Otherwise returns a network error code.
   int CreateSystemProxyConfigService(
       scoped_ptr<net::ProxyConfigService>* config_service) {
-#if defined(OS_LINUX) || defined(OS_OPENBSD)
+#if defined(OS_LINUX) || defined(OS_BSD)
     // TODO(eroman): This is not supported on Linux yet, because of how
     // construction needs ot happen on the UI thread.
     return net::ERR_NOT_IMPLEMENTED;
