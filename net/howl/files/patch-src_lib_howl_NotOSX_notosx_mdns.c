--- src/lib/howl/NotOSX/notosx_mdns.c.orig	Thu Apr 15 10:34:27 2004
+++ src/lib/howl/NotOSX/notosx_mdns.c	Thu Apr 15 10:34:38 2004
@@ -54,7 +54,7 @@
 #include <salt/assert.h>
 #include <salt/log.h>
 #include <stdio.h>
-
+#include <sys/time.h>
 
 #define CACHE_SIZE 750
 
