--- tcpdump.c.orig	Wed Mar 17 19:47:48 2004
+++ tcpdump.c	Wed Mar 31 01:03:41 2004
@@ -69,6 +69,12 @@
 #include "gmt2local.h"
 #include "pcap-missing.h"
 
+/*
+ * XXX: quick and dirty until FreeBSD defines DLT_IEEE802_11_RADIO in
+ * <net/bpf.h>. -bms
+ */
+#include "ieee802_11_radio.h"
+
 int dflag;			/* print filter code */
 int eflag;			/* print ethernet header */
 int fflag;			/* don't translate "foreign" IP address */
