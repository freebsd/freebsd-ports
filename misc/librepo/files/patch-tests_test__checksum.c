--- tests/test_checksum.c.orig	2020-09-20 19:02:27 UTC
+++ tests/test_checksum.c
@@ -6,7 +6,7 @@
 #include <string.h>
 #include <sys/types.h>
 #include <sys/stat.h>
-#include <sys/xattr.h>
+#include "xattr.h"
 #include <fcntl.h>
 
 #include "librepo/util.h"
