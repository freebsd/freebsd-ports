Index: imtest/imtest.c
diff -u imtest/imtest.c.orig imtest/imtest.c
--- imtest/imtest.c.orig	Sun Jul 13 05:10:56 2003
+++ imtest/imtest.c	Fri Jul 18 00:52:29 2003
@@ -51,6 +51,7 @@
 #include <sys/stat.h>
 #include <fcntl.h>
 
+#include <limits.h>
 #include <stdlib.h>
 #include <stdio.h>
 #include <string.h>
@@ -419,8 +420,8 @@
 }
 
 
-char *var_tls_CAfile="";
-char *var_tls_CApath="";
+static char *var_tls_CAfile="";
+static char *var_tls_CApath="";
 /*
  * This is the setup routine for the SSL client. 
  *
