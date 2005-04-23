--- cherokee/socket.h.orig	Sun Mar  6 08:09:33 2005
+++ cherokee/socket.h	Fri Apr  1 13:09:44 2005
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
