--- filter/pdftops.c.orig	2015-07-04 11:21:47 UTC
+++ filter/pdftops.c
@@ -535,7 +535,7 @@ main(int  argc,				/* I - Number of comm
 
   if (renderer == PDFTOPS)
   {
-    pdf_argv[0] = (char *)"pdftops";
+    pdf_argv[0] = (char *)"%%LOCALBASE%%/bin/pdftops";
     pdf_argc    = 1;
   }
   else if (renderer == GS)
