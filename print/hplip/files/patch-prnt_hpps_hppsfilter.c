--- prnt/hpps/hppsfilter.c.orig	2019-11-04 10:12:15 UTC
+++ prnt/hpps/hppsfilter.c
@@ -104,7 +104,7 @@ static void open_tempbookletfile(char *mode)
     if(ptempbooklet_file == NULL)
     {
             fprintf(stderr, "ERROR: Unable to open temp file %s\n", temp_filename);
-            return 1;
+            return;
     }  
     chmod(temp_filename, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
 
