--- fdtoverlay.c.orig	2017-11-27 12:39:15 UTC
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
