--- disco.c.orig	2014-08-08 23:55:22.000000000 -0400
+++ disco.c	2014-08-08 23:56:40.000000000 -0400
@@ -1031,7 +1031,7 @@
     if (!fp_file)
     {
         fprintf(stderr, "No fingerprint file found\n");
-        return;
+        return -1;
     }
 
     while (fgets(infile, 1500, fp_file) != NULL && infile[0] != '\n')
