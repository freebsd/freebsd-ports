--- defines.h.orig	2014-05-06 16:38:13.055354417 -0700
+++ defines.h	2014-05-06 16:42:19.536056294 -0700
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
