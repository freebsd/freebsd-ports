We don't need to fflush the file, since it is opened read-only.

--- fileconf.c.orig	2014-05-10 17:03:59 UTC
+++ fileconf.c
@@ -278,10 +278,6 @@ read_file(char *filename, int fd)
     cf->cf_next = file_base;
     file_base = cf;
 
-    /* don't close as underlying fd may still be used by calling function */
-    if (fflush(file) != 0)
-        error_e("could not fflush() file_name");
-
     Free_safe(default_line.cl_runas);
     Free_safe(default_line.cl_mailto);
     Free_safe(default_line.cl_tz);
