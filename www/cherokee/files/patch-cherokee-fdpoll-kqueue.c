--- cherokee/fdpoll-kqueue.c.orig	Fri May 27 02:42:27 2005
+++ cherokee/fdpoll-kqueue.c	Fri Sep 16 00:03:37 2005
@@ -27,6 +27,7 @@
 #include "fdpoll-protected.h"
 
 #include <stdio.h>
+#include <sys/types.h>
 #include <sys/event.h>
 #include <sys/time.h>
 #include <unistd.h>
