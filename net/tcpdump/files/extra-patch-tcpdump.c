--- tcpdump.c.orig	Wed Dec 10 19:04:45 2003
+++ tcpdump.c	Wed Dec 10 19:09:25 2003
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
