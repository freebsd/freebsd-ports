--- src/script_engine.c.orig
+++ src/script_engine.c
@@ -54,6 +54,7 @@
 #include "snapshot.h"
 #include "engine.h"
 #include "history.h"
+#define PTHREAD_MUTEX_RECURSIVE_NP PTHREAD_MUTEX_RECURSIVE
 /*
 #define LOG
 */
