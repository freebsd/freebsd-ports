--- src/etpan/etpan-thread-manager.c.orig	Thu Sep  1 12:57:20 2005
+++ src/etpan/etpan-thread-manager.c	Thu Sep  1 12:57:57 2005
@@ -4,10 +4,10 @@
 
 #ifdef HAVE_LIBETPAN
 
+#include <pthread.h>
 #include "etpan-thread-manager.h"
 
 #include <stdlib.h>
-#include <pthread.h>
 #include <libetpan/mailsem.h>
 #include <semaphore.h>
 #include <unistd.h>
