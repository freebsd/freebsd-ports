--- ./src/npw-wrapper.c.orig	Sun Mar  4 23:01:22 2007
+++ ./src/npw-wrapper.c	Wed Apr  4 20:20:59 2007
@@ -28,6 +28,7 @@
 #include <unistd.h>
 #include <pthread.h>
 #include <semaphore.h>
+#include <signal.h>
 #include <sys/wait.h>
 
 #include <glib.h>
