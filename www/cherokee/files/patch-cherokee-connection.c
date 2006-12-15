--- cherokee/connection.c.orig	Mon Dec 11 11:44:26 2006
+++ cherokee/connection.c	Thu Dec 14 09:50:08 2006
@@ -32,6 +32,7 @@
 #include <fcntl.h>
 #include <time.h>
 #include <sys/types.h>
+#include <limits.h>
 
 #ifdef HAVE_PWD_H
 # include <pwd.h>
