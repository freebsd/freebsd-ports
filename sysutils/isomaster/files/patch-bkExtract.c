--- bk/bkExtract.c.orig	Sun Jan  7 20:00:36 2007
+++ bk/bkExtract.c
@@ -223,6 +223,7 @@
             else
             {
                 printf("trying to extract something that's not a file or directory, ignored\n");fflush(NULL);
+		rc = BKERROR_WRONG_EXTRACT_FILE;
             }
             
             if(rc <= 0)
