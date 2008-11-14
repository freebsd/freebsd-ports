--- src/knockd.c.orig	2008-11-14 16:32:31.000000000 +0000
+++ src/knockd.c	2008-11-14 16:33:22.000000000 +0000
@@ -200,7 +200,7 @@
 	}
 
 #if defined(__FreeBSD__) || defined(__APPLE__)
-	cap = pcap_open_live(o_int, 65535, 0, 1, pcapErr);
+	cap = pcap_open_live(o_int, 65535, 0, 1000, pcapErr);
 #else
 	cap = pcap_open_live(o_int, 65535, 0, 0, pcapErr);
 #endif	
