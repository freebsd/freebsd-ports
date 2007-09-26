--- smbval/smbencrypt.inc.c.orig	Wed Sep 26 12:43:32 2007
+++ smbval/smbencrypt.inc.c	Wed Sep 26 12:45:29 2007
@@ -19,7 +19,8 @@
 #include <arpa/inet.h>
 #include <dirent.h>
 #include <string.h>
-#include <sys/vfs.h>
+#include <sys/param.h>
+#include <sys/mount.h>
 #include <netinet/in.h>
 
 #include "smblib-priv.h"
