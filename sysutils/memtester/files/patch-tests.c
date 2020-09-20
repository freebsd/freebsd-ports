--- tests.c.orig	2012-06-09 21:45:22 UTC
+++ tests.c
@@ -22,6 +22,16 @@
 #include "sizes.h"
 #include "memtester.h"
 
+union {
+    unsigned char bytes[UL_LEN/8];
+    ul val;
+} mword8;
+
+union {
+    unsigned short u16s[UL_LEN/16];
+    ul val;
+} mword16;
+
 char progress[] = "-\\|/";
 #define PROGRESSLEN 4
 #define PROGRESSOFTEN 2500
