--- cdpd.c.orig	2016-03-22 18:37:16 UTC
+++ cdpd.c
@@ -606,7 +606,7 @@ cdp_debug_packet(struct cdp_interface* c
 int
 main(int argc, char* argv[])
 { 
-	char c;
+	int c;
 	int timeout=60, ret=0;
 	unsigned char buffer[1600];
 	int offset;
