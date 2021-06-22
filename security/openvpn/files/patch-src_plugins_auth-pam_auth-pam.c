--- src/plugins/auth-pam/auth-pam.c.orig	2021-06-21 04:44:39 UTC
+++ src/plugins/auth-pam/auth-pam.c
@@ -39,6 +39,7 @@
 #include <stdio.h>
 #include <string.h>
 #include <ctype.h>
+#include <limits.h>
 #include <unistd.h>
 #include <stdlib.h>
 #include <sys/types.h>
