--- defines.h.orig	2005-03-30 19:56:58 UTC
+++ defines.h
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
@@ -59,11 +62,11 @@
 #ifdef HAVE_NET_ROUTE_H
 #include <net/route.h>
 #endif
-#ifdef HAVE_PCAP_H
-#include <pcap.h>
-#endif
 #ifdef HAVE_NET_BPF_H
 #include <net/bpf.h>
+#endif
+#ifdef HAVE_PCAP_H
+#include <pcap.h>
 #endif
 #ifdef HAVE_NET_ETHERNET_H
 #include <net/ethernet.h>
