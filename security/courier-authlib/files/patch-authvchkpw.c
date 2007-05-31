--- authvchkpw.c.orig	Thu May 31 07:04:07 2007
+++ authvchkpw.c	Thu May 31 07:03:44 2007
@@ -28,6 +28,9 @@
         int (*callback)(struct authinfo *, void *),
                         void *arg);
 
+static int auth_vchkpw_login(const char *service, char *authdata,
+        int (*callback_func)(struct authinfo *, void *), void *callback_arg);
+
 extern FILE *authvchkpw_file(const char *, const char *);
 
 struct callback_info {
