--- modules/tm_posix/tm_posix.cpp.orig	Sat Jun 26 14:32:53 2004
+++ modules/tm_posix/tm_posix.cpp	Fri Jul 16 16:32:28 2004
@@ -6,7 +6,7 @@
 #define _POSIX_C_SOURCE 199309
 #include <botan/tm_posix.h>
 #include <botan/util.h>
-#include <time.h>
+#include <sys/time.h>
 
 #ifndef CLOCK_REALTIME
   #define CLOCK_REALTIME 0
