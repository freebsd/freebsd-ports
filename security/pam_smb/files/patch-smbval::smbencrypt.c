--- smbval/smbencrypt.c.orig	Tue Feb 19 10:34:51 2002
+++ smbval/smbencrypt.c	Tue Feb 19 10:39:28 2002
@@ -21,6 +21,7 @@
 */
=20
 #include <string.h>
+#include <sys/types.h>
 #include <arpa/inet.h>
 #include <dirent.h>
 #include <string.h>
