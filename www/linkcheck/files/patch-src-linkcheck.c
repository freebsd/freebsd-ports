--- src/linkcheck.c.org	Tue Feb 17 14:48:59 2004
+++ src/linkcheck.c	Tue Feb 17 14:25:24 2004
@@ -47,6 +47,8 @@
 # endif
 #endif
 
+# include <arpa/inet.h>
+
 #ifdef  HAVE_NETINET_IN_H
 # include <netinet/in.h>
 #endif/*HAVE_NETINET_IN_H*/
