--- libGeoIP/GeoIPBitReader.c.orig	Thu Dec 26 20:09:06 2002
+++ libGeoIP/GeoIPBitReader.c	Thu Dec 26 20:08:44 2002
@@ -32,7 +32,7 @@
 }
 
 unsigned long GeoIPBitReader_read(GeoIPBitReader * gibr, short int numBits) {
-	ulong num = 0;
+	unsigned long num = 0;
 	int i, bit;
 	int bytes_read;
 
