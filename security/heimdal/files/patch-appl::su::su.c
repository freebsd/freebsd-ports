--- appl/su/su.c.orig	Wed Aug 22 15:35:38 2001
+++ appl/su/su.c	Wed Oct 31 13:14:50 2001
@@ -152,7 +152,11 @@
 #ifdef KRB5
     krb5_error_code ret;
     krb5_principal p;
+    char *login_name = NULL;
 	
+#if defined(HAVE_GETLOGIN) && !defined(POSIX_GETLOGIN)
+    login_name = getlogin();
+#endif
     ret = krb5_init_context (&context);
     if (ret) {
 #if 0
@@ -161,9 +165,11 @@
 	return 1;
     }
 	
+    if (login_name == NULL || strcmp (login_name, "root") == 0) 
+	login_name = login_info->pw_name;
     if (strcmp (su_info->pw_name, "root") == 0)
 	ret = krb5_make_principal(context, &p, NULL, 
-				  login_info->pw_name,
+				  login_name,
 				  kerberos_instance,
 				  NULL);
     else
@@ -282,7 +288,6 @@
     int i, optind = 0;
     char *su_user;
     struct passwd *su_info;
-    char *login_user = NULL;
     struct passwd *login_info;
 
     struct passwd *pwd;
@@ -325,10 +330,6 @@
     if (su_info == NULL)
 	errx (1, "malloc: out of memory");
     
-#if defined(HAVE_GETLOGIN) && !defined(POSIX_GETLOGIN)
-    login_user = getlogin();
-#endif
-    if(login_user == NULL || (pwd = getpwnam(login_user)) == NULL)
 	pwd = getpwuid(getuid());
     if(pwd == NULL)
 	errx(1, "who are you?");
