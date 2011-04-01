--- ./chrome/browser/net/connection_tester.cc.orig	2010-12-16 02:11:55.000000000 +0100
+++ ./chrome/browser/net/connection_tester.cc	2010-12-20 20:15:08.000000000 +0100
@@ -179,7 +179,7 @@
   // Otherwise returns a network error code.
   int CreateSystemProxyConfigService(
       scoped_ptr<net::ProxyConfigService>* config_service) {
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(FREEBSD)
     // TODO(eroman): This is not supported on Linux yet, because of how
     // construction needs ot happen on the UI thread.
     return net::ERR_NOT_IMPLEMENTED;
