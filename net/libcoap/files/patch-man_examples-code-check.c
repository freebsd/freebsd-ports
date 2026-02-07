--- man/examples-code-check.c.orig	2021-06-26 19:47:52 UTC
+++ man/examples-code-check.c
@@ -16,6 +16,7 @@
 #include <stdlib.h>
 #include <sys/stat.h>
 #include <sys/types.h>
+#include <sys/wait.h>
 #include <dirent.h>
 #include <errno.h>
 #include <string.h>
