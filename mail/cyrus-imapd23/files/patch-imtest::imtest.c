Index: imtest/imtest.c
diff -u imtest/imtest.c.orig imtest/imtest.c
--- imtest/imtest.c.orig	Wed Mar 19 10:29:22 2003
+++ imtest/imtest.c	Sun May 11 16:47:11 2003
@@ -417,8 +417,8 @@
 }
 
 
-char *var_tls_CAfile="";
-char *var_tls_CApath="";
+static char *var_tls_CAfile="";
+static char *var_tls_CApath="";
 /*
  * This is the setup routine for the SSL client. 
  *
