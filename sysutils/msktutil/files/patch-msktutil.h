--- ./msktutil.h.orig	2012-08-29 17:25:54.000000000 -0400
+++ ./msktutil.h	2012-08-29 17:26:12.000000000 -0400
@@ -43,6 +43,8 @@
 #include <netdb.h>
 #include <sys/socket.h>
 #include <sys/utsname.h>
+#include <netinet/in.h>
+#include <arpa/inet.h>
 #include <ldap.h>
 
 #ifdef HAVE_COM_ERR_H
