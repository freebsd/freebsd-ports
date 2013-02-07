--- pgpsendmail.c.orig	1995-01-17 09:55:45.000000000 +0900
+++ pgpsendmail.c	2012-10-24 16:20:57.000000000 +0900
@@ -152,7 +152,7 @@
 		  flag no_advertising, flag add_key) );
 
 
-void main (argc, argv, envp)
+int main (argc, argv, envp)
 int argc;
 char *argv[];
 char *envp[];
@@ -184,7 +184,9 @@
     extern char *username;
     extern char **recipients;
     ERRNO_TYPE errno;
+#if 0
     extern char *sys_errlist[];
+#endif
 
     if (argv[0] == NULL)
     {
@@ -940,7 +942,9 @@
     char *argv[6];
     extern char *username;
     ERRNO_TYPE errno;
+#if 0
     extern char *sys_errlist[];
+#endif
 
     /*  Make stdout go to  stderr  */
     (void) fflush (stdout);
@@ -1250,7 +1254,9 @@
     extern char *buffer;
     extern char *pgppath;
     ERRNO_TYPE errno;
+#if 0
     extern char *sys_errlist[];
+#endif
 
     if (!sign)
     {
