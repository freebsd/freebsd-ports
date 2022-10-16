--- source3/registry/tests/test_regfio.c.orig	2019-05-07 08:38:21 UTC
+++ source3/registry/tests/test_regfio.c
@@ -24,6 +24,7 @@
 
 #include <errno.h>
 #include <stdlib.h>
+#include <unistd.h>
 #include <sys/types.h>
 #include <sys/stat.h>
 #include <fcntl.h>
