--- ./src/sss_client/pam_test_client.c.orig	2011-08-29 11:39:05.000000000 -0400
+++ ./src/sss_client/pam_test_client.c	2011-10-13 12:15:03.000000000 -0400
@@ -24,12 +24,13 @@
 
 #include <stdio.h>
 #include <unistd.h>
+#include <string.h>
 
 #include <security/pam_appl.h>
-#include <security/pam_misc.h>
+#include <security/openpam.h>
 
 static struct pam_conv conv = {
-    misc_conv,
+    openpam_ttyconv,
     NULL
 };
 
