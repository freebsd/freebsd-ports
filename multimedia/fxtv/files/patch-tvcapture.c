--- work/fxtv-1.03/tvcapture.c.orig	Tue Nov 26 19:30:12 2002
+++ work/fxtv-1.03/tvcapture.c	Tue Nov 26 19:30:27 2002
@@ -34,6 +34,7 @@
 #include <stdlib.h>
 #include <fcntl.h>
 #include <errno.h>
+#include <sys/types.h>
 #include <sys/mman.h>
 #ifdef __NetBSD__
 # include <dev/ic/bt8xx.h>
