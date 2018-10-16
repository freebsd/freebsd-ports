--- src/test.c.orig	2018-05-04 14:52:04 UTC
+++ src/test.c
@@ -22,9 +22,10 @@
 
 #include <stdio.h>
 #include <stdlib.h>
+#include <string.h>
+#include <unistd.h>
 
 #include <security/pam_appl.h>
-#include <security/pam_misc.h>
 #include <security/pam_modules.h>
 
 #ifndef LIBDIR
@@ -42,7 +43,7 @@ int main(int argc, const char **argv)
 	};
 	pam_handle_t *pamh = NULL;
 	struct pam_conv conv = {
-		misc_conv,
+		openpam_ttyconv,
 		NULL,
 	};
 	int r;
