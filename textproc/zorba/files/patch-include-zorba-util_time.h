--- include/zorba/util/time.h.orig	2011-09-15 11:16:07.000000000 +0200
+++ include/zorba/util/time.h	2011-09-15 11:19:48.000000000 +0200
@@ -73,7 +73,11 @@
 
     inline void get_current_cputime (cputime& t)
     {
+#if defined( __FreeBSD__ )
+      clock_gettime(CLOCK_PROF, &t);
+#else
       clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &t);
+#endif
     }
 
 #elif defined(ZORBA_HAVE_RUSAGE_FUNCTION)
