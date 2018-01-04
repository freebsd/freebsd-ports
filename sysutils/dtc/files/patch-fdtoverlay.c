--- fdtoverlay.c.orig	2017-09-27 10:00:10 UTC
+++ fdtoverlay.c
@@ -26,7 +26,9 @@
 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>
+#ifndef __FreeBSD__
 #include <alloca.h>
+#endif
 #include <inttypes.h>
 
 #include <libfdt.h>
