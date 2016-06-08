--- ./chrome/browser/net/connection_tester.cc.orig	2014-04-30 22:41:58.000000000 +0200
+++ ./chrome/browser/net/connection_tester.cc	2014-05-04 14:38:46.000000000 +0200
@@ -213,7 +213,7 @@
   // Otherwise returns a network error code.
   int CreateSystemProxyConfigService(
       scoped_ptr<net::ProxyConfigService>* config_service) {
-#if defined(OS_LINUX) || defined(OS_OPENBSD)
+#if defined(OS_LINUX) || defined(OS_BSD)
     // TODO(eroman): This is not supported on Linux yet, because of how
     // construction needs ot happen on the UI thread.
     return net::ERR_NOT_IMPLEMENTED;
