--- libfprint/data.c.orig	2009-03-07 23:42:59.000000000 +0300
+++ libfprint/data.c	2009-03-07 23:43:09.000000000 +0300
@@ -19,6 +19,7 @@
 
 #include <config.h>
 #include <errno.h>
+#include <stdlib.h>
 #include <string.h>
 #include <sys/types.h>
 #include <sys/stat.h>
