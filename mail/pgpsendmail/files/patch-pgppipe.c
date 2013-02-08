--- pgppipe.c.orig	1994-12-07 20:03:39.000000000 +0900
+++ pgppipe.c	2012-10-24 16:20:24.000000000 +0900
@@ -52,7 +52,7 @@
 #include "pgpsendmail.h"
 
 
-void main (argc, argv, envp)
+int main (argc, argv, envp)
 int argc;
 char *argv[];
 char *envp[];
@@ -67,7 +67,9 @@
     char *pgp_start_line = "-----BEGIN PGP MESSAGE-----\n";
     char *pgp_end_line = "-----END PGP MESSAGE-----\n";
     ERRNO_TYPE errno;
+#if 0
     extern char *sys_errlist[];
+#endif
 
     if ( ( pgppath = getenv ("PGPPATH") ) == NULL )
     {
