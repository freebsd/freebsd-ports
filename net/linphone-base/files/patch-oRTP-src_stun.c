--- oRTP/src/stun.c.orig	2008-06-24 14:21:05.000000000 +0000
+++ oRTP/src/stun.c	2008-06-24 14:21:47.000000000 +0000
@@ -770,7 +770,7 @@
       asm("rdtsc" : "=A" (tick));
 #elif defined (__SUNPRO_CC) && defined( __sparc__ )	
       tick = gethrtime();
-#elif defined(__MACH__) 
+#elif defined(__MACH__) || defined(__sparc64__)
       {
 	int fd=open("/dev/random",O_RDONLY);
 	read(fd,&tick,sizeof(tick));
