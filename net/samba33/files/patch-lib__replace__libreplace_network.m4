--- ./lib/replace/libreplace_network.m4.orig	2009-03-12 09:47:20.000000000 +0000
+++ ./lib/replace/libreplace_network.m4	2009-03-14 05:49:10.000000000 +0000
@@ -8,12 +8,15 @@
 
 AC_CHECK_HEADERS(sys/socket.h netinet/in.h netdb.h arpa/inet.h)
 AC_CHECK_HEADERS(netinet/in_systm.h)
-AC_CHECK_HEADERS([netinet/ip.h], [], [], [#ifdef HAVE_NETINET_IN_H
-#include <netinet/in.h>
-#endif
-#ifdef HAVE_NETINET_IN_SYSTM_H
-#include <netinet/in_systm.h>
-#endif])
+AC_CHECK_HEADERS([netinet/ip.h], [], [], [
+	#include <sys/types.h>
+	#ifdef HAVE_NETINET_IN_H
+	#include <netinet/in.h>
+	#endif
+	#ifdef HAVE_NETINET_IN_SYSTM_H
+	#include <netinet/in_systm.h>
+	#endif
+])
 AC_CHECK_HEADERS(netinet/tcp.h netinet/in_ip.h)
 AC_CHECK_HEADERS(sys/sockio.h sys/un.h)
 
