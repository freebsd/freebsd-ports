Index: imtest/imtest.c
diff -u imtest/imtest.c.orig imtest/imtest.c
--- imtest/imtest.c.orig	Sun May 11 17:48:08 2003
+++ imtest/imtest.c	Sun May 11 17:50:04 2003
@@ -291,8 +291,8 @@
 }
 
 
-char *var_tls_CAfile="";
-char *var_tls_CApath="";
+static char *var_tls_CAfile="";
+static char *var_tls_CApath="";
  /*
   * This is the setup routine for the SSL client. 
   *
