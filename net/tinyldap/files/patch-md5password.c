--- md5password.c.orig	Thu Feb  5 01:08:49 2004
+++ md5password.c	Thu Feb 26 16:03:58 2004
@@ -1,3 +1,6 @@
+#ifdef __FreeBSD__
+#include <sys/types.h>
+#endif
 #include <md5.h>
 #include <string.h>
 #include "buffer.h"
