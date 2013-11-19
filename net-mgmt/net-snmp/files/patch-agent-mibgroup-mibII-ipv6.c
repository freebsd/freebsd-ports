--- agent/mibgroup/mibII/ipv6.c.orig	2012-10-10 00:28:58.000000000 +0200
+++ agent/mibgroup/mibII/ipv6.c	2013-11-19 21:01:33.000000000 +0100
@@ -55,6 +55,7 @@
 #endif
 #include <net/if.h>
 #if HAVE_NET_IF_VAR_H
+#define _WANT_IFADDR
 #include <net/if_var.h>
 #endif
 #if HAVE_NET_IF_DL_H
