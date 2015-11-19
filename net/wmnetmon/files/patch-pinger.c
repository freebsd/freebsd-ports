--- pinger.c.orig	2000-06-17 11:01:23 UTC
+++ pinger.c
@@ -14,7 +14,9 @@
 #include <netdb.h>
 #include <errno.h>
 #include <stdlib.h>
+#if ! (defined __FreeBSD__ || defined __DragonFly__)
 #include <malloc.h>
+#endif
 #include <unistd.h>
 #include "list.h"
 #include "config.h"
