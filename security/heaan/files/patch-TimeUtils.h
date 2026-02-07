--- ../src/TimeUtils.h.orig	2020-10-12 09:20:15.992285000 +0200
+++ ../src/TimeUtils.h	2020-10-12 09:20:25.674915000 +0200
@@ -8,6 +8,7 @@
 #ifndef HEAAN_TIMEUTILS_H_
 #define HEAAN_TIMEUTILS_H_
 
+#include <sys/time.h>
 #include <iostream>
 
 struct timeval;
