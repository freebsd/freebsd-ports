--- ./chrome/browser/net/connection_tester.cc.orig	2014-08-20 21:02:09.000000000 +0200
+++ ./chrome/browser/net/connection_tester.cc	2014-08-22 15:06:25.000000000 +0200
@@ -217,7 +217,7 @@
   // Otherwise returns a network error code.
   int CreateSystemProxyConfigService(
       scoped_ptr<net::ProxyConfigService>* config_service) {
-#if defined(OS_LINUX) || defined(OS_OPENBSD)
+#if defined(OS_LINUX) || defined(OS_BSD)
     // TODO(eroman): This is not supported on Linux yet, because of how
     // construction needs ot happen on the UI thread.
     return net::ERR_NOT_IMPLEMENTED;
