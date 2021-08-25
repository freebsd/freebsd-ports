--- prnt/backend/hp.c.orig	2022-02-23 07:41:04 UTC
+++ prnt/backend/hp.c
@@ -649,7 +649,7 @@ static FILE* create_out_file(char* job_id, char* user_
 
     if (temp_fp)
     {
-        chmod(fname, S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH);
+        chmod(fname, S_IRUSR | S_IWUSR | S_IRGRP | 0 | S_IROTH);
     }
     else
     {
