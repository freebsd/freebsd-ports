--- ./misc/tune2fs.c.orig	2013-06-21 04:43:42.000000000 +0200
+++ ./misc/tune2fs.c	2013-06-28 01:08:29.000000000 +0200
@@ -25,8 +25,6 @@
  * 94/03/06	- Added the checks interval from Uwe Ohse (uwe@tirka.gun.de)
  */
 
-#define _XOPEN_SOURCE 600 /* for inclusion of strptime() */
-#define _BSD_SOURCE /* for inclusion of strcasecmp() */
 #include "config.h"
 #include <fcntl.h>
 #include <grp.h>
@@ -48,6 +46,9 @@
 #include <libgen.h>
 #include <limits.h>
 
+#include <netinet/in.h>
+#include <strings.h>
+
 #include "ext2fs/ext2_fs.h"
 #include "ext2fs/ext2fs.h"
 #include "et/com_err.h"
