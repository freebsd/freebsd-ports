--- filter/pdftops.c.orig	2016-01-19 22:12:43 UTC
+++ filter/pdftops.c
@@ -532,12 +532,12 @@ main(int  argc,				/* I - Number of comm
 
   if (renderer == PDFTOPS)
   {
-    pdf_argv[0] = (char *)"pdftops";
+    pdf_argv[0] = (char *)"%%LOCALBASE%%/bin/pdftops";
     pdf_argc    = 1;
   }
   else if (renderer == GS)
   {
-    pdf_argv[0] = (char *)"gs";
+    pdf_argv[0] = (char *)"%%LOCALBASE%%/bin/gs";
     pdf_argv[1] = (char *)"-q";
     pdf_argv[2] = (char *)"-dNOPAUSE";
     pdf_argv[3] = (char *)"-dBATCH";
@@ -552,13 +552,13 @@ main(int  argc,				/* I - Number of comm
   }
   else if (renderer == PDFTOCAIRO)
   {
-    pdf_argv[0] = (char *)"pdftocairo";
+    pdf_argv[0] = (char *)"%%LOCALBASE%%/bin/pdftocairo";
     pdf_argv[1] = (char *)"-ps";
     pdf_argc    = 2;
   }
   else
   {
-    pdf_argv[0] = (char *)"acroread";
+    pdf_argv[0] = (char *)"%%LOCALBASE%%/bin/acroread";
     pdf_argv[1] = (char *)"-toPostScript";
     pdf_argc    = 2;
   }
