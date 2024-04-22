--- tests/test_checksum.c.orig	2024-03-26 13:28:08 UTC
+++ tests/test_checksum.c
@@ -6,7 +6,7 @@
 #include <string.h>
 #include <sys/types.h>
 #include <sys/stat.h>
-#include <sys/xattr.h>
+#include "xattr.h"
 #include <fcntl.h>
 
 #include "librepo/util.h"
