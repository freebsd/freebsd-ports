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
@@ -886,6 +886,12 @@
     }
     
     if (*str != '\r') {
+	/* trim CRLF */
+	char *p = str + strlen(str) - 1;
+	if (p >= str && *p == '\n') *p-- = '\0';
+	if (p >= str && *p == '\r') *p-- = '\0';
+
+	/* alloc space for decoded response */
 	len = strlen(str) + 1;
 	*line = malloc(len);
 	if ((*line) == NULL) {
