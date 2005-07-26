--- udf_unix.c	Sun Jun 26 00:02:48 2005
+++ udf_unix.c	Mon Jul 25 11:50:58 2005
@@ -433,7 +433,7 @@
 		if (!udf_bufcache->finish_purgethread) {
 			do {
 				/* determine the time we want to wake up again * */
-				clock_gettime(CLOCK_MONOTONIC, &wakeup);
+				clock_gettime(CLOCK_REALTIME, &wakeup);
 				wakeup.tv_sec += UDF_BUFCACHE_IDLE_SECS;
 
 				/* ask for more requests */
