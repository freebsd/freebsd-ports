--- mount/freebsd-mounts-7.c.orig	2015-03-13 23:51:39 UTC
+++ mount/freebsd-mounts-7.c
@@ -1,3 +1,5 @@
+#include <stdlib.h>
+#include <string.h>
 #include <stdio.h>
 #include <errno.h>
 #include <sys/param.h>
