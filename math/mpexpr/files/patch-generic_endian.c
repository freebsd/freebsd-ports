--- generic/endian.c.orig	2016-09-16 07:35:45 UTC
+++ generic/endian.c
@@ -35,7 +35,7 @@
 char byte[8] = { (char)0x12, (char)0x36, (char)0x48, (char)0x59,
 		 (char)0x01, (char)0x23, (char)0x45, (char)0x67 };
 
-main()
+int main()
 {
     /* pointers into the byte order array */
     int *intp = (int *)byte;
