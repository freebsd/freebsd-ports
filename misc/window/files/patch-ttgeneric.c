--- ttgeneric.c.orig	2008-07-12 06:05:22 UTC
+++ ttgeneric.c
@@ -43,6 +43,13 @@ static char rcsid[] =
 #include "ww.h"
 #include "tt.h"
 
+struct tt tt;
+char tt_strings[1024];
+char *tt_strp;
+char *tt_ob;
+char *tt_obp;
+char *tt_obe;
+
 char PC, *BC, *UP;
 
 	/* normal frame */
