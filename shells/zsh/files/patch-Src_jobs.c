--- Src/jobs.c.orig	2014-08-23 20:40:52.000000000 +0200
+++ Src/jobs.c	2014-09-10 10:33:50.283018759 +0200
@@ -694,15 +694,14 @@
     /* go ahead and compute these, since almost every TIMEFMT will have them */
     elapsed_time = real->tv_sec + real->tv_usec / 1000000.0;
 
+    long clktck = get_clktck();
 #ifdef HAVE_GETRUSAGE
     user_time = ti->ru_utime.tv_sec + ti->ru_utime.tv_usec / 1000000.0;
     system_time = ti->ru_stime.tv_sec + ti->ru_stime.tv_usec / 1000000.0;
-    total_time = user_time + system_time;
-    percent = 100.0 * total_time
-	/ (real->tv_sec + real->tv_usec / 1000000.0);
+    percent = 100.0 * total_time / elapsed_time;
+    total_time *= (double) clktck;
 #else
     {
-	long clktck = get_clktck();
 	user_time    = ti->ut / (double) clktck;
 	system_time  = ti->st / (double) clktck;
 	percent      =  100.0 * (ti->ut + ti->st)
@@ -796,7 +795,7 @@
 #endif
 #ifdef HAVE_STRUCT_RUSAGE_RU_MAXRSS
 	    case 'M':
-		fprintf(stderr, "%ld", ti->ru_maxrss / 1024);
+		fprintf(stderr, "%ld", ti->ru_maxrss);
 		break;
 #endif
 #ifdef HAVE_STRUCT_RUSAGE_RU_MAJFLT
