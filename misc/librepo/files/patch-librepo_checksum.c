--- librepo/checksum.c.orig	2020-09-20 18:54:37 UTC
+++ librepo/checksum.c
@@ -26,7 +26,7 @@
 #include <errno.h>
 #include <sys/types.h>
 #include <sys/stat.h>
-#include <sys/xattr.h>
+#include "xattr.h"
 #include <unistd.h>
 #include <openssl/evp.h>
 
