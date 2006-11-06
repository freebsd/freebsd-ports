--- src/engine.c.orig
+++ src/engine.c
@@ -33,6 +33,7 @@
 #include "engine.h"
 #include "ui.h"
 #include "utils.h"
+#define PTHREAD_RECURSIVE_MUTEX_INITIALIZER_NP PTHREAD_MUTEX_INITIALIZER
 
 se_t *gse; /* global script engine */
 xine_t *xine; /* global xine instance */
