--- gavl/time.c.orig	2010-01-14 19:32:51.000000000 +0100
+++ gavl/time.c	2010-03-30 13:55:24.113853853 +0200
@@ -44,7 +44,7 @@
 
 
 /* Sleep for a specified time */
-#ifdef HAVE_CLOCK_MONOTONIC
+#if defined(HAVE_CLOCK_MONOTONIC) || defined(__FreeBSD__)
 void gavl_time_delay(gavl_time_t * t)
   {
   struct timespec tm;
@@ -53,8 +53,12 @@
   tm.tv_sec = *t / 1000000;
   tm.tv_nsec = (*t % 1000000)*1000;
   
+#if defined(__FreeBSD__)
+  while(nanosleep(&tm, &rem))
+#else
   while(clock_nanosleep(CLOCK_MONOTONIC, 0,
                         &tm, &rem))
+#endif
     {
     if(errno == EINTR)
       {
