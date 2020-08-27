--- src/anubisadm.h.orig	2020-08-27 18:29:03 UTC
+++ src/anubisadm.h
@@ -26,10 +26,10 @@
 
 typedef int (*operation_fp) (int, char **);
 
-char *authid;
-char *username;
-char *rcfile;
-char *password;
+extern char *authid;
+extern char *username;
+extern char *rcfile;
+extern char *password;
 
 int op_create (int argc, char **argv);
 int op_list (int argc, char **argv);
