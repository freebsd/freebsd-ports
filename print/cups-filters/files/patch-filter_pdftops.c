--- filter/pdftops.c.orig	2014-08-21 10:11:24.448404905 -0400
+++ filter/pdftops.c	2014-08-21 10:12:00.298402116 -0400
@@ -535,7 +535,7 @@
 
   if (renderer == PDFTOPS)
   {
-    pdf_argv[0] = (char *)"pdftops";
+    pdf_argv[0] = (char *)"%%LOCALBASE%%/bin/pdftops";
     pdf_argc    = 1;
   }
   else if (renderer == GS)
