--- ./src/arping.c.orig	2010-12-15 02:40:26.572881702 +0000
+++ ./src/arping.c	2010-12-15 02:41:01.891883112 +0000
@@ -75,15 +75,15 @@
 #include <libnet.h>
 #endif
 
+#if HAVE_NET_BPF_H
+#include <net/bpf.h>
+#endif
+
 #if HAVE_WIN32_LIBNET_H
 #include <win32/libnet.h>
 #endif
 #include <pcap.h>
 
-#if HAVE_NET_BPF_H
-#include <net/bpf.h>
-#endif
-
 #ifndef ETH_ALEN
 #define ETH_ALEN 6
 #endif
