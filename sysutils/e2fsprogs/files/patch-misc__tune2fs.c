--- misc/tune2fs.c.orig	2014-08-02 20:26:22 UTC
+++ misc/tune2fs.c
@@ -25,7 +25,6 @@
  * 94/03/06	- Added the checks interval from Uwe Ohse (uwe@tirka.gun.de)
  */
 
-#define _XOPEN_SOURCE 600 /* for inclusion of strptime() */
 #include "config.h"
 #include <fcntl.h>
 #include <grp.h>
@@ -52,6 +51,9 @@
 #include <libgen.h>
 #include <limits.h>
 
+#include <netinet/in.h>
+#include <strings.h>
+
 #include "ext2fs/ext2_fs.h"
 #include "ext2fs/ext2fs.h"
 #include "et/com_err.h"
