--- swlibs/fxmisc/fxos.c.orig	Wed Jan 15 10:01:58 2003
+++ swlibs/fxmisc/fxos.c	Sun Jul  1 01:56:10 2007
@@ -27,13 +27,22 @@
 
 #include <fxos.h>
 
-/* return current time in seconds (floating point)      */
-float fxTime(void)
-{
 #if defined ( __sparc__ ) || defined ( __DJGPP__ )
 /* times returns 0 in BSD Unix, so we use ftime instead */
 #   include <sys/types.h>
 #   include <sys/timeb.h>
+#elif defined(__FreeBSD__)
+#   include <sys/time.h>
+#else
+#   include <sys/types.h>
+#   include <sys/times.h>
+#   include <sys/param.h>
+#endif
+
+/* return current time in seconds (floating point)      */
+float fxTime(void)
+{
+#if defined ( __sparc__ ) || defined ( __DJGPP__ )
     struct timeb tb;
     static time_t once;                 // saves first time value
 
@@ -43,15 +52,11 @@
     return (tb.time - once) + tb.millitm * .001;
     
 #elif defined(__FreeBSD__)
-#include <sys/time.h>
     struct timeval t;
     struct timezone tz;
     gettimeofday(&t, &tz);
     return ((float)t.tv_sec + ((float)t.tv_usec)/1000000.0);
 #else
-#   include <sys/types.h>
-#   include <sys/times.h>
-#   include <sys/param.h>
     struct tms foo;
     return times(&foo)/(float)HZ;
 #endif
