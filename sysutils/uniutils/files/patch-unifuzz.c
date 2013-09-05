--- unifuzz.c.orig	2008-04-04 06:30:58.000000000 +0200
+++ unifuzz.c	2013-09-05 09:50:49.000000000 +0200
@@ -97,7 +97,7 @@
 }
 
 /* Emit the middle character from each range */
-EmitAllRanges(short AboveBMPP) {
+void EmitAllRanges(short AboveBMPP) {
   int i;
   UTF32 scp;
   extern int Ranges_Defined;
