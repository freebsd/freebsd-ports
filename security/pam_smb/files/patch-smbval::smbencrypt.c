--- smbval/smbencrypt.c.orig	Sat Aug 19 12:58:07 2000
+++ smbval/smbencrypt.c	Thu Feb 21 07:11:09 2002
@@ -21,6 +21,7 @@
 */
 
 #include <string.h>
+#include <sys/types.h>
 #include <arpa/inet.h>
 #include <dirent.h>
 #include <string.h>
