--- dvdimagecmp.c.orig	Tue Jan  4 11:54:52 2005
+++ dvdimagecmp.c	Thu Oct 13 09:29:12 2005
@@ -27,9 +27,11 @@
 #define _FILE_OFFSET_BITS	64
 
 #include <stdlib.h>
+#include <string.h>
+#include <sys/types.h>
 #include <errno.h>
 #include <stdio.h>
-#include <getopt.h>
+#include <unistd.h>
 #include <errno.h>
 #include <ctype.h>
 #include <time.h>
