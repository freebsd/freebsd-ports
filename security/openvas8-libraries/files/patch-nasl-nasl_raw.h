--- nasl/nasl_raw.h.orig	2015-08-03 10:14:31 UTC
+++ nasl/nasl_raw.h
@@ -43,6 +43,8 @@
 
 #include <netinet/tcp.h>
 #include <netinet/udp.h>
+#include <netinet/in.h>
+#include <netinet/ip.h>
 #include <netinet/ip_icmp.h>
 
 #endif
