--- src/socket.h.orig	Sat Jun 19 23:03:54 2004
+++ src/socket.h	Sat Jul 17 20:36:02 2004
@@ -45,12 +45,12 @@
 # include <sys/socket.h>
 #endif
 
-#ifdef HAVE_ARPA_INET_H
-# include <arpa/inet.h>
-#endif
-
 #ifdef HAVE_NETINET_IN_H
 # include <netinet/in.h>
+#endif
+
+#ifdef HAVE_ARPA_INET_H
+# include <arpa/inet.h>
 #endif
 
 #if defined(HAVE_GNUTLS)
