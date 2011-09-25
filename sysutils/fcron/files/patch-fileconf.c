We don't need to fflush the file, since it is opened read-only.

--- fileconf.c.orig	2011-07-18 19:55:28.726082293 +0400
+++ fileconf.c	2011-07-18 19:55:37.988079816 +0400
@@ -264,10 +264,6 @@
     cf->cf_next = file_base;
     file_base = cf;
 
-    /* don't close as underlying fd may still be used by calling function */
-    if (fflush(file) != 0)
-        error_e("could not fflush() file_name");
-    
     free(default_line.cl_runas);
     free(default_line.cl_mailto);
     free(default_line.cl_tz);
