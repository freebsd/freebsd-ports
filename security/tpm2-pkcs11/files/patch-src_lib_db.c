--- src/lib/db.c.orig	2023-01-20 15:32:09 UTC
+++ src/lib/db.c
@@ -12,8 +12,6 @@
 #include <libgen.h>
 #include <unistd.h>
 
-#include <linux/limits.h>
-
 #include <sys/file.h>
 #include <sys/stat.h>
 #include <sys/types.h>
