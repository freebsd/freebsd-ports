--- src/zm_thread.h.orig	2009-06-08 02:20:17.000000000 -0700
+++ src/zm_thread.h	2014-07-23 00:50:23.000000000 -0700
@@ -21,6 +21,7 @@
 #define ZM_THREAD_H
 
 #include <pthread.h>
+#include <unistd.h>
 #include "zm_exception.h"
 #include "zm_utils.h"
 
