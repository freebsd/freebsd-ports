--- blitz/timer.h.orig	Thu Jul 25 16:47:56 2002
+++ blitz/timer.h	Thu Jul 25 16:48:12 2002
@@ -41,6 +41,8 @@
 #ifndef BZ_TIMER_H
 #define BZ_TIMER_H
 
+#include <sys/time.h>
+
 #ifndef BZ_BLITZ_H
  #include <blitz/blitz.h>
 #endif
