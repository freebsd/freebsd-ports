--- nss/passwd.c.orig	2021-01-17 13:59:24 UTC
+++ nss/passwd.c
@@ -45,8 +45,8 @@ static nss_status_t read_passwd(TFILE *fp, struct pass
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
