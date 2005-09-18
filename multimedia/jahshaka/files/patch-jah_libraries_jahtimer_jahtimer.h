--- jah/libraries/jahtimer/jahtimer.h.orig
+++ jah/libraries/jahtimer/jahtimer.h
@@ -10,7 +10,7 @@
 #define JAHTIMER_H
 
 #include <qstring.h>
-#include <sys/timeb.h>
+#include <sys/time.h>
 
 #include "jahtracer.h"
 
@@ -28,7 +28,8 @@
     
 private:
 
-    timeb                           current_time;
+    struct timeval		current_time;
+    //timeb                           current_time;
     //static timeb                  current_time;
     
     //used for timing effects
