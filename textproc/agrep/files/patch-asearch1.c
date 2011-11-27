--- asearch1.c.orig	1992-01-17 22:00:38.000000000 +0100
+++ asearch1.c	2011-11-27 12:07:32.000000000 +0100
@@ -8,7 +8,7 @@
 extern int num_of_matched;
 
 
-asearch1(old_D_pat, Text, D)
+void asearch1(old_D_pat, Text, D)
 char old_D_pat[]; int Text; register unsigned D;
 {
   register unsigned end, i, r1, r2, r3, r4, r5, CMask, D_Mask, Init0, k, endpos; 
