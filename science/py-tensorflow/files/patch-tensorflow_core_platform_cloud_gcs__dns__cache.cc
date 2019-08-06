--- tensorflow/core/platform/cloud/gcs_dns_cache.cc.orig	2019-06-18 23:48:23.000000000 +0100
+++ tensorflow/core/platform/cloud/gcs_dns_cache.cc	2019-07-06 18:15:09.827112000 +0100
@@ -24,6 +24,11 @@
 #endif
 #include <sys/types.h>
 
+#ifdef __FreeBSD__ 
+#include <sys/socket.h>
+#include <netinet/in.h>
+#endif
+
 namespace tensorflow {
 
 namespace {
