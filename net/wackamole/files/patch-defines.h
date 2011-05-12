--- defines.h.orig	2005-03-30 21:56:58.000000000 +0200
+++ defines.h	2011-05-12 02:51:55.000000000 +0200
@@ -13,6 +13,9 @@
 #ifdef HAVE_STRINGS_H
 #include <strings.h>
 #endif
+#ifdef HAVE_STRING_H
+#include <string.h>
+#endif
 #ifdef HAVE_ERRNO_H
 #include <errno.h>
 #endif
@@ -59,12 +62,12 @@
 #ifdef HAVE_NET_ROUTE_H
 #include <net/route.h>
 #endif
-#ifdef HAVE_PCAP_H
-#include <pcap.h>
-#endif
 #ifdef HAVE_NET_BPF_H
 #include <net/bpf.h>
 #endif
+#ifdef HAVE_PCAP_H
+#include <pcap.h>
+#endif
 #ifdef HAVE_NET_ETHERNET_H
 #include <net/ethernet.h>
 #endif
