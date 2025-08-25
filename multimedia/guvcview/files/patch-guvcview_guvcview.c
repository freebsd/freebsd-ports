--- guvcview/guvcview.c.orig	2024-11-02 13:15:33 UTC
+++ guvcview/guvcview.c
@@ -28,6 +28,7 @@
 #include <sys/resource.h>
 #include <sys/stat.h>
 #include <sys/syscall.h>
+#include <pthread_np.h>
 #include <unistd.h>
 
 #include "config.h"
@@ -226,8 +227,8 @@ int main(int argc, char *argv[]) {
 #endif
 
   if (debug_level > 1)
-    printf("GUVCVIEW: main thread (tid: %u)\n",
-           (unsigned int)syscall(SYS_gettid));
+    printf("GUVCVIEW: main thread (tid: %d)\n",
+           pthread_getthreadid_np());
 
   /*set the v4l2 core verbosity*/
   v4l2core_set_verbosity(debug_level);
@@ -393,8 +394,7 @@ int main(int argc, char *argv[]) {
         gui_error("Guvcview error", "could not start the video capture thread",
                   1);
       } else if (debug_level > 2)
-        printf("GUVCVIEW: created capture thread with tid: %u\n",
-               (unsigned int)capture_thread);
+        printf("GUVCVIEW: created capture thread\n");
 
       struct timespec now;
       clock_gettime(CLOCK_REALTIME, &now);
