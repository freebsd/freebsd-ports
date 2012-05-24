Additional patch to support older FreeBSD versions.

Please Note: 7.4, 8.1+, 9.0+ and current don't need this patch
EOL page: http://security.freebsd.org/#unsup

Even I don't agree with running security software on EOL OS versions
(upgrade is an easy task) this patch will stay until the next nmap
release ( build will be tested only on supported OS versions )


======================================================================
--- ./libnetutil/netutil.cc.orig	2012-05-18 00:56:38.000000000 +0200
+++ ./libnetutil/netutil.cc	2012-05-23 22:38:14.000000000 +0200
@@ -158,6 +158,7 @@
 #endif
 #endif
 #ifndef NETINET_IP_H  /* This guarding is needed for at least some versions of OpenBSD */
+#include <netinet/in_systm.h>
 #include <netinet/ip.h> 
 #define NETINET_IP_H
 #endif
