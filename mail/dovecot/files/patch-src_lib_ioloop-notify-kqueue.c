--- src/lib/ioloop-notify-kqueue.c.orig	2022-06-14 06:55:03 UTC
+++ src/lib/ioloop-notify-kqueue.c
@@ -11,6 +11,7 @@
 
 #include "ioloop-private.h"
 #include "llist.h"
+#include "time-util.h"
 #include <unistd.h>
 #include <fcntl.h>
 #include <sys/types.h>
