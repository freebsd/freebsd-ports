--- htpasswd.c.orig	Sun Feb  4 20:13:04 2007
+++ htpasswd.c	Sun Feb  4 20:12:32 2007
@@ -41,6 +41,7 @@
 #include <errno.h>
 #include <unistd.h>
 #include <stdlib.h>
+#include <string.h>
 #include <pwd.h>
 
 #define MAX_PASS 32
