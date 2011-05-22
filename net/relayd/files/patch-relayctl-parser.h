--- relayctl/parser.h.orig	2011-05-22 10:56:33.769045780 +0200
+++ relayctl/parser.h	2011-05-22 10:56:46.122442873 +0200
@@ -23,7 +23,9 @@
 	SHOW_RDRS,
 	SHOW_RELAYS,
 	SHOW_SESSIONS,
+#ifndef __FreeBSD__
 	SHOW_ROUTERS,
+#endif
 	RDR_DISABLE,
 	RDR_ENABLE,
 	TABLE_DISABLE,
