--- src/libbacklight.c.orig	2015-10-24 00:02:43 UTC
+++ src/libbacklight.c
@@ -35,11 +35,13 @@
 #include <stdio.h>
 #include <stdlib.h>
 #include <unistd.h>
-#include <linux/types.h>
 #include <dirent.h>
 #include <drm.h>
 #include <fcntl.h>
+#if !defined(__FreeBSD__)
+#include <linux/types.h> // We need anything from here??
 #include <malloc.h>
+#endif
 #include <string.h>
 #include <errno.h>
 
