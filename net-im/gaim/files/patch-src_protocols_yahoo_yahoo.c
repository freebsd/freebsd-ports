--- src/protocols/yahoo/yahoo.c.orig	Wed Jan 15 21:19:22 2003
+++ src/protocols/yahoo/yahoo.c	Wed Jan 15 21:19:46 2003
@@ -1196,6 +1196,9 @@
 	yahoo_packet_hash(pkt, 1, gc->displayname);
 	yahoo_packet_hash(pkt, 5, who);
 	yahoo_packet_hash(pkt, 14, utf8);
+	yahoo_packet_hash(pkt, 63, ";0");
+	yahoo_packet_hash(pkt, 64, "0");
+	yahoo_packet_hash(pkt, 97, "1");
 
 	g_free (utf8);
 
