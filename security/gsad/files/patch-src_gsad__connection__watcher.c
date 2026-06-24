--- src/gsad_connection_watcher.c.orig	2026-06-23 07:45:31 UTC
+++ src/gsad_connection_watcher.c
@@ -5,6 +5,7 @@
 
 #include "gsad_connection_watcher.h"
 
+#include <sys/socket.h>
 #include <pthread.h>
 #include <unistd.h> /* for sleep */
 
