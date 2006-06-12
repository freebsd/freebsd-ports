--- src/test.c.orig	Thu Jun  1 15:13:06 2006
+++ src/test.c	Thu Jun  1 15:13:15 2006
@@ -2,7 +2,7 @@
 #include <stdlib.h>
 
 #include <security/pam_appl.h>
-#include <security/pam_misc.h>
+#include <security/pam_modules.h>
 
 int main(int argc, char **argv)
 {
