--- asearch.c.orig	1992-01-24 01:49:08 UTC
+++ asearch.c
@@ -6,7 +6,9 @@ extern int DELIMITER, FILENAMEONLY, INVE
 extern CHAR CurrentFileName[];
 extern int I, num_of_matched, TRUNCATE;
 
-asearch(old_D_pat, text, D)
+void asearch0(CHAR old_D_pat[], int text, register unsigned D);
+
+void asearch(old_D_pat, text, D)
 CHAR old_D_pat[]; int text; register unsigned D;
 {
   register unsigned i, c, r1, r2, CMask, r_NO_ERR, r_Init1; 
@@ -178,7 +180,7 @@ Nextchar1: i=i+1;
   return;
 }
 
-asearch0(old_D_pat, text, D)
+void asearch0(old_D_pat, text, D)
 CHAR old_D_pat[]; int text; register unsigned D;
 {
   register unsigned i, c, r1, r2, r3, CMask, r_NO_ERR, r_Init1,  end, endpos; 
