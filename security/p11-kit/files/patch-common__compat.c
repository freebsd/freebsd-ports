--- common/compat.c.orig	2014-10-06 05:29:32 UTC
+++ common/compat.c
@@ -34,12 +34,6 @@
 
 #include "config.h"
 
-/*
- * This is needed to expose pthread_mutexattr_settype and PTHREAD_MUTEX_DEFAULT
- * on older pthreads implementations
- */
-#define _XOPEN_SOURCE 700
-
 #include "compat.h"
 
 #include <assert.h>
