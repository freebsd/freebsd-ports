--- modules/proto_tls/proto_tls.c.orig	2016-05-30 14:13:27 UTC
+++ modules/proto_tls/proto_tls.c
@@ -42,6 +42,7 @@
 #include <openssl/opensslv.h>
 #include <openssl/err.h>
 
+#include <netinet/in.h>
 #include <netinet/in_systm.h>
 #include <netinet/tcp.h>
 #include <netinet/ip.h>
