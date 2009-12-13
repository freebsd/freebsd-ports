--- ./src/image.c.orig	2009-12-13 18:45:05.000000000 +0100
+++ ./src/image.c	2009-12-13 18:45:26.000000000 +0100
@@ -1398,7 +1398,7 @@
 
 char *getimagescale(uint64_t kb, int rate)
 {
-	static char buffer[6];
+	static char buffer[7];
 	uint32_t limit[3];
 	int unit;
 	
