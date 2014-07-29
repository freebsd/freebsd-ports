--- src/iplog_pcap.c.orig	Mon Jan  1 17:02:14 2001
+++ src/iplog_pcap.c	Mon Aug 27 16:38:50 2001
@@ -211,6 +211,7 @@
 	u_char fstring[1024], *temp, errbuf[PCAP_ERRBUF_SIZE];
 	struct bpf_program filt;
 	u_int i = 0;
+	int b = 1;
 
 	pdata->pd =
 		pcap_open_live(pdata->name, SNAPLEN, opt_enabled(PROMISC), 0, errbuf);
@@ -229,6 +230,13 @@
 		pcap_close(pdata->pd);
 		return (-1);
 	}
+
+#ifdef __FreeBSD__
+#include <osreldate.h>
+#if __FreeBSD_version >= 420001
+	ioctl(pcap_fileno(pdata->pd), BIOCIMMEDIATE, &b);
+#endif
+#endif
 
 #ifdef __linux__
 	/*
