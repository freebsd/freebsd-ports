--- cherokee/fdpoll-kqueue.c.orig	Wed Sep 13 21:45:31 2006
+++ cherokee/fdpoll-kqueue.c	Wed Sep 13 21:45:13 2006
@@ -27,6 +27,7 @@
 #include "fdpoll-protected.h"
 
 #include <stdio.h>
+#include <sys/types.h>
 #include <sys/event.h>
 #include <sys/time.h>
 #include <unistd.h>
