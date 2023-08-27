--- nss/passwd.c.orig	2019-11-02 16:23:46.000000000 +0100
+++ nss/passwd.c	2023-05-29 19:22:02.235416000 +0200
@@ -45,8 +45,8 @@
   READ_BUF_STRING(fp, result->pw_dir);
   READ_BUF_STRING(fp, result->pw_shell);
 #ifdef HAVE_STRUCT_PASSWD_PW_CLASS
-  /* set the user access class to an empty string */
-  result->pw_class = result->pw_name + strlen(result->pw_name);
+  /* set the user access class to an empty string only if empty */
+  READ_BUF_STRING(fp, result->pw_class);
 #endif /* HAVE_STRUCT_PASSWD_PW_CLASS */
   return NSS_STATUS_SUCCESS;
 }
