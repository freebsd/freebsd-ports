--- src/devtools/mkb_dump.c.orig	2020-11-08 18:24:41 UTC
+++ src/devtools/mkb_dump.c
@@ -26,6 +26,7 @@
 #include <string.h>
 #include <errno.h>
 #include <inttypes.h>
+#include <sys/types.h>
 
 #include "read_file.h"
 
