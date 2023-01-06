--- image-android-sparse.c.orig	2023-01-06 17:52:40 UTC
+++ image-android-sparse.c
@@ -15,7 +15,7 @@
  */
 
 #include <confuse.h>
-#include <endian.h>
+#include <sys/endian.h>
 #include <errno.h>
 #include <fcntl.h>
 #include <stdlib.h>
