--- src/arping.c.orig	2012-12-29 16:30:08.000000000 +0100
+++ src/arping.c	2013-10-23 10:30:44.000000000 +0200
@@ -81,13 +81,14 @@
 #include <libnet.h>
 #endif
 
+#if HAVE_NET_BPF_H
+#include <net/bpf.h>
+#endif
+
 #if HAVE_WIN32_LIBNET_H
 #include <win32/libnet.h>
 #endif
 
-#if HAVE_NET_BPF_H
-#include <net/bpf.h>
-#endif
 #include <pcap.h>
 
 #include "arping.h"
