--- asearch.c.orig	1992-01-24 02:49:08.000000000 +0100
+++ asearch.c	2011-11-27 12:05:20.000000000 +0100
@@ -6,7 +6,9 @@
 extern CHAR CurrentFileName[];
 extern int I, num_of_matched, TRUNCATE;
 
-asearch(old_D_pat, text, D)
+void asearch0(CHAR old_D_pat[], int text, register unsigned D);
+
+void asearch(old_D_pat, text, D)
 CHAR old_D_pat[]; int text; register unsigned D;
 {
   register unsigned i, c, r1, r2, CMask, r_NO_ERR, r_Init1; 
@@ -178,7 +180,7 @@
   return;
 }
 
-asearch0(old_D_pat, text, D)
+void asearch0(old_D_pat, text, D)
 CHAR old_D_pat[]; int text; register unsigned D;
 {
   register unsigned i, c, r1, r2, r3, CMask, r_NO_ERR, r_Init1,  end, endpos; 
