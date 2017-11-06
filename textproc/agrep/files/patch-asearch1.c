--- asearch1.c.orig	1992-01-17 21:00:38 UTC
+++ asearch1.c
@@ -8,7 +8,7 @@ extern char CurrentFileName[];
 extern int num_of_matched;
 
 
-asearch1(old_D_pat, Text, D)
+void asearch1(old_D_pat, Text, D)
 char old_D_pat[]; int Text; register unsigned D;
 {
   register unsigned end, i, r1, r2, r3, r4, r5, CMask, D_Mask, Init0, k, endpos; 
