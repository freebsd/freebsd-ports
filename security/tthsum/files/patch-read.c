--- read.c.orig	Tue Jun 28 02:50:50 2005
+++ read.c	Sun Sep 25 14:21:38 2005
@@ -38,9 +38,11 @@
 #include <sys/stat.h>
 #include <fcntl.h>
 #include <limits.h>
-#include <malloc.h>
+#include <stdlib.h>
 #include <string.h>
 #include <stdio.h>
+
+#define O_LARGEFILE 0
 
 struct readmmap_data {
 #ifdef _WIN32
