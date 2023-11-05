--- unifuzz.c.orig	2020-11-20 08:28:53 UTC
+++ unifuzz.c
@@ -97,7 +97,7 @@ EmitBadUTF8 () {
 }
 
 /* Emit the middle character from each range */
-EmitAllRanges(short AboveBMPP) {
+void EmitAllRanges(short AboveBMPP) {
   int i;
   UTF32 scp;
   extern int Ranges_Defined;
