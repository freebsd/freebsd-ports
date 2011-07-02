--- src/file_magic.c.orig	2011-06-19 22:52:25.000000000 +0900
+++ src/file_magic.c	2011-06-26 15:30:02.000000000 +0900
@@ -9,7 +9,9 @@
 #include <magic.h>
 #endif
 
-#include <sys/dir.h>
+#include <sys/types.h>
+#include <dirent.h>
+#include <limits.h>
 
 #include <stdio.h>
 #include <stdlib.h>
