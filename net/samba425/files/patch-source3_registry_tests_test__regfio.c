--- source3/registry/tests/test_regfio.c.orig	2026-01-20 15:42:54 UTC
+++ source3/registry/tests/test_regfio.c
@@ -25,6 +25,7 @@
 
 #include <errno.h>
 #include <stdlib.h>
+#include <unistd.h>
 #include <sys/types.h>
 #include <sys/stat.h>
 #include <fcntl.h>
