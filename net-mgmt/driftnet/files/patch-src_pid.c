--- src/pid.c.orig	2014-09-14 19:16:31 UTC
+++ src/pid.c
@@ -14,7 +14,9 @@
 
 #include "compat.h"
 
-//#include <sys/stat.h>
+#ifdef __FreeBSD__
+#include <sys/stat.h>
+#endif
 #include <fcntl.h>
 #include <errno.h>
 #include <stdio.h>
