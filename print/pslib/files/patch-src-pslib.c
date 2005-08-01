--- src/pslib.c.orig	Wed Jul 27 15:08:15 2005
+++ src/pslib.c	Fri Jul 29 01:56:04 2005
@@ -29,6 +29,7 @@
 #include <strings.h>
 #include <time.h>
 #include <math.h>
+#include <sys/types.h>
 #include <sys/select.h>
 #include <sys/stat.h>
 #ifndef WIN32
