--- ./libv4l2util/v4l2_driver.c.orig	2011-02-09 23:04:27.000000000 +0100
+++ ./libv4l2util/v4l2_driver.c	2011-06-03 19:08:13.000000000 +0200
@@ -15,7 +15,11 @@
 #include <assert.h>
 #include <errno.h>
 #include <fcntl.h>
+#ifndef __FreeBSD__
 #include <malloc.h>
+#else
+#include <stdlib.h>
+#endif
 #include <stdio.h>
 #include <string.h>
 #include <unistd.h>
