--- intrpalt.c.bak	2002-04-27 22:35:18.000000000 +0400
+++ intrpalt.c	2012-02-25 22:34:56.000000000 +0400
@@ -71,7 +71,8 @@
 byte *szHouseFile(i)
 int i;
 {
-  byte szFileName[16], szFileNumber[8];
+  static byte szFileName[16];
+  byte szFileNumber[8];
 
   sprintf (szFileNumber, "%i", i);
   sprintf (szFileName, "house");
@@ -85,7 +86,8 @@
 int i;
 bool trflag;
 {
-  byte szFileName[16], szFileNumber[8];
+  static byte szFileName[16];
+  byte szFileNumber[8];
 
   sprintf (szFileNumber, "%i", i);
   if (i < 10)
@@ -104,7 +106,8 @@
 int i;
 bool trflag;
 {
-  byte szFileName[16], szFileNumber[8];
+  static byte szFileName[16];
+  byte szFileNumber[8];
 
   sprintf (szFileNumber, "%i", i);
   if (i < 10)
