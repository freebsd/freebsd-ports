--- mod_auth_any.c.orig	Tue Jan  9 05:48:20 2001
+++ mod_auth_any.c	Tue Mar 25 01:09:55 2003
@@ -121,6 +121,7 @@
   
 */
 
+char* bash_single_quote_escape_string(const char *);
   
 /* NB: debugging stuff */
 extern int errno;
@@ -180,13 +181,25 @@
     const char *rpw, *w;
     FILE* ext_authprog;
     FILE* fp;
+    char *escaped_user, *escaped_password;
     
     l = (char*) malloc (MAX_STRING_LEN * sizeof(char));
+    memset (l, '\0', MAX_STRING_LEN);
     execstr = (char*) malloc (MAX_STRING_LEN * sizeof(char));
 
     setenv ("REMOTE_ADDR", r -> connection -> remote_ip, 1);
+
+    /* escape the user name and the password */
+    escaped_user = bash_single_quote_escape_string(user);
+    escaped_password = bash_single_quote_escape_string(password);
+
     /* open the program stream */
-    snprintf (execstr, MAX_STRING_LEN, "%s %s \"%s\"", auth_pwfile, user, password);
+    snprintf (execstr, MAX_STRING_LEN, "%s %s %s", auth_pwfile, escaped_user, escaped_password);
+
+    /* free the escaped user and password before we forget */
+    free(escaped_user);
+    free(escaped_password);
+
     if (!(ext_authprog = popen (execstr, "r"))) {
 
       ap_log_rerror (APLOG_MARK, APLOG_ERR, r, "Could not popen() on program: %s: %s",
