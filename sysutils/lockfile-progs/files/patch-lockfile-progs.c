--- lockfile-progs.c.orig	2024-12-11 18:54:17 UTC
+++ lockfile-progs.c
@@ -278,6 +278,8 @@ get_status_code_string(int status)
 static char*
 get_status_code_string(int status)
 {
+  char *err = NULL;
+
   switch (status)
   {
     case L_SUCCESS:
@@ -309,15 +311,12 @@ get_status_code_string(int status)
       break;
 
     default:
-      char *err = 0L;
-      int rc = asprintf(&err, "unrecognized error status (%d)", status);
-      if (rc < 0)
+      if (asprintf(&err, "unrecognized error status (%d)", status) < 0)
       {
         msg(stderr, "unable to generate error message");
         exit(2);
       }
       return err;
-      break;
   }
 }
 
