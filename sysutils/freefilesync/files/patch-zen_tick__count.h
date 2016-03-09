--- ../../zen/tick_count.h.orig	2016-03-07 17:18:11.038986000 +0800
+++ ../../zen/tick_count.h	2016-03-07 17:20:01.674266000 +0800
@@ -128,7 +128,7 @@
 #elif defined ZEN_LINUX
     //gettimeofday() seems fine but is deprecated
     timespec now = {};
-    if (::clock_gettime(CLOCK_MONOTONIC_RAW, &now) != 0) //CLOCK_MONOTONIC measures time reliably across processors!
+    if (::clock_gettime(CLOCK_MONOTONIC, &now) != 0) //CLOCK_MONOTONIC measures time reliably across processors!
         return TickVal();
 
 #elif defined ZEN_MAC
