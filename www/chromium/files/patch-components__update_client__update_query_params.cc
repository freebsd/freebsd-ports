--- components/update_client/update_query_params.cc.orig	2015-04-19 21:26:41.000000000 +0200
+++ components/update_client/update_query_params.cc	2015-04-19 21:27:50.000000000 +0200
@@ -31,6 +31,8 @@
     "linux";
 #elif defined(OS_OPENBSD)
     "openbsd";
+#elif defined(OS_FREEBSD)
+    "freebsd";
 #else
 #error "unknown os"
 #endif
