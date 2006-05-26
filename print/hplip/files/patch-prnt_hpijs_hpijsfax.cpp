--- prnt/hpijs/hpijsfax.cpp.orig	Tue Feb 21 13:19:54 2006
+++ prnt/hpijs/hpijsfax.cpp	Fri May 26 11:56:49 2006
@@ -39,7 +39,11 @@
 #include <string.h>
 #include <unistd.h>
 #include <fcntl.h>
+#ifdef __FreeBSD__
+#include <inttypes.h>
+#else
 #include <stdint.h>
+#endif
 #include <time.h>
 #include <sys/time.h>
 #include <math.h>
@@ -297,8 +301,8 @@
 
 	memset (&tv, 0, sizeof (tv));
 	gettimeofday (&tv, NULL);
-	cur_time = localtime (&tv.tv_sec);
-    memset (hpFileName, 0, 256);
+	cur_time = localtime ((const time_t *)&tv.tv_sec);
+	memset (hpFileName, 0, 256);
 	sprintf (hpFileName, "%s/hplipfax%d%d%d%d%d%d.g3", getenv ("TMPDIR"),
 						  cur_time->tm_year+1900, cur_time->tm_mon+1, cur_time->tm_mday,
 						  cur_time->tm_hour, cur_time->tm_min, cur_time->tm_sec);
