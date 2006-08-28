--- src/engine.c.orig	Fri Jun 30 18:56:00 2006
+++ src/engine.c	Tue Jul 11 01:36:59 2006
@@ -36,7 +36,7 @@
 
 se_t *gse; /* global script engine */
 xine_t *xine; /* global xine instance */
-pthread_mutex_t engine_lock = PTHREAD_RECURSIVE_MUTEX_INITIALIZER_NP;
+pthread_mutex_t engine_lock = PTHREAD_MUTEX_INITIALIZER;
 
 gboolean initialised = FALSE;
 
