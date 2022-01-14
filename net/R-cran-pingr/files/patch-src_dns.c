--- src/dns.c.orig	2022-01-14 08:39:31 UTC
+++ src/dns.c
@@ -262,6 +262,10 @@ SEXP r_nsl(SEXP hostname, SEXP server, SEXP class, SEX
 
 #else
 
+#ifdef __FreeBSD__
+#include <netinet/in.h>
+#endif
+
 #include <resolv.h>
 #include <netinet/in.h>
 #include <arpa/inet.h>
