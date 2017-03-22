--- dialects/freebsd/dlsof.h.orig	2017-01-14 23:50:37.000000000 -0800
+++ dialects/freebsd/dlsof.h	2017-03-22 00:12:47.309579000 -0700
@@ -154,12 +154,14 @@
 #include <netinet/in_systm.h>
 #include <netinet/ip.h>
 #include <net/route.h>
+#define	_WANT_INPCB
 #include <netinet/in_pcb.h>
 #include <netinet/ip_var.h>
 #include <netinet/tcp.h>
 #include <netinet/tcpip.h>
 #include <netinet/tcp_fsm.h>
 #include <netinet/tcp_timer.h>
+#define	_WANT_TCPCB
 #include <netinet/tcp_var.h>
 #include <sys/ucred.h>
 #include <sys/uio.h>
