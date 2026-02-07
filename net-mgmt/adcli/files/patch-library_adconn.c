--- library/adconn.c.orig	2022-09-28 17:04:28 UTC
+++ library/adconn.c
@@ -31,6 +31,7 @@
 #include <krb5/krb5.h>
 #include <ldap.h>
 #include <sasl/sasl.h>
+#include <netinet/in.h>
 
 #include <sys/types.h>
 #include <sys/socket.h>
