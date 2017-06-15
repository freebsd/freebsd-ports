--- libchula/test/util_test.c.orig	2014-07-09 21:59:50 UTC
+++ libchula/test/util_test.c
@@ -40,6 +40,10 @@
 # include <syslog.h>
 #endif
 
+#ifdef HAVE_NETINET_IN_H
+# include <netinet/in.h>
+#endif
+
 #ifdef HAVE_ARPA_INET_H
 # include <arpa/inet.h>
 #endif
