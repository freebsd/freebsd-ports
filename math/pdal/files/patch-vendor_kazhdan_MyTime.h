--- vendor/kazhdan/MyTime.h.orig	2018-04-06 19:43:22 UTC
+++ vendor/kazhdan/MyTime.h
@@ -30,7 +30,6 @@ DAMAGE.
 #define MY_TIME_INCLUDED
 
 #include <string.h>
-#include <sys/timeb.h>
 #ifndef WIN32
 #include <sys/time.h>
 #endif // WIN32
