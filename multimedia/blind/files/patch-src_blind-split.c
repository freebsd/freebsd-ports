--- src/blind-split.c.orig	2017-05-06 11:27:39 UTC
+++ src/blind-split.c
@@ -2,7 +2,11 @@
 #include "stream.h"
 #include "util.h"
 
+#if defined(__FreeBSD__) || defined(__OpenBSD__) || defined(__NetBSD__) || defined(__DragonFly__)
+#include <stdlib.h>
+#else
 #include <alloca.h>
+#endif
 #include <fcntl.h>
 #include <inttypes.h>
 #include <limits.h>
