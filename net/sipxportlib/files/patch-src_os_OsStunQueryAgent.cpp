--- src/os/OsStunQueryAgent.cpp.orig	Wed Apr 11 17:12:46 2007
+++ src/os/OsStunQueryAgent.cpp	Wed Apr 11 17:13:45 2007
@@ -841,7 +841,7 @@
         tick |= lowtick;
 #elif defined(__GNUC__) && ( defined(__i686__) || defined(__i386__) )
 asm("rdtsc" : "=A" (tick));
-#elif defined (__SUNPRO_CC) || defined( __sparc__ )
+#elif defined (__SUNPRO_CC) || (defined( __sparc__ ) && !defined(__FreeBSD__))
         tick = gethrtime();
 #elif defined(__pingtel_on_posix__) || defined(_VXWORKS)
 	tick = getpid();
