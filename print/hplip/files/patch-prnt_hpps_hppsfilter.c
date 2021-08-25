--- prnt/hpps/hppsfilter.c.orig	2022-02-23 07:41:05 UTC
+++ prnt/hpps/hppsfilter.c
@@ -53,7 +53,7 @@ static void get_LogLevel ()
     FILE    *fp;
     char    str[258];
     char    *p;
-    fp = fopen ("/etc/cups/cupsd.conf", "r");
+    fp = fopen ("/usr/local/etc/cups/cupsd.conf", "r");
     if (fp == NULL)
         return;
     while (!feof (fp))
@@ -105,7 +105,7 @@ static void open_tempbookletfile(char *mode)
     if(ptempbooklet_file == NULL)
     {
             fprintf(stderr, "ERROR: Unable to open temp file %s\n", temp_filename);
-            return 1;
+            return;
     }  
     chmod(temp_filename, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
 
