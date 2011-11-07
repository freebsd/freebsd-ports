--- Src/jobs.c.orig	2011-11-06 19:20:13.978321106 +0100
+++ Src/jobs.c	2011-11-07 07:45:47.012600236 +0100
@@ -583,7 +583,6 @@
 }
 
 /**/
-#ifndef HAVE_GETRUSAGE
 static long clktck = 0;
 
 /**/
@@ -613,7 +612,6 @@
 #endif
 }
 /**/
-#endif
 
 /**/
 static void
@@ -656,14 +654,14 @@
     /* go ahead and compute these, since almost every TIMEFMT will have them */
     elapsed_time = real->tv_sec + real->tv_usec / 1000000.0;
 
+    set_clktck();
 #ifdef HAVE_GETRUSAGE
     user_time = ti->ru_utime.tv_sec + ti->ru_utime.tv_usec / 1000000.0;
     system_time = ti->ru_stime.tv_sec + ti->ru_stime.tv_usec / 1000000.0;
     total_time = user_time + system_time;
-    percent = 100.0 * total_time
-	/ (real->tv_sec + real->tv_usec / 1000000.0);
+    percent = 100.0 * total_time / elapsed_time;
+    total_time *= (double) clktck;
 #else
-    set_clktck();
     user_time    = ti->ut / (double) clktck;
     system_time  = ti->st / (double) clktck;
     percent      =  100.0 * (ti->ut + ti->st)
@@ -749,7 +747,7 @@
 #endif
 #ifdef HAVE_STRUCT_RUSAGE_RU_MAXRSS
 	    case 'M':
-		fprintf(stderr, "%ld", ti->ru_maxrss / 1024);
+		fprintf(stderr, "%ld", ti->ru_maxrss);
 		break;
 #endif
 #ifdef HAVE_STRUCT_RUSAGE_RU_MAJFLT
