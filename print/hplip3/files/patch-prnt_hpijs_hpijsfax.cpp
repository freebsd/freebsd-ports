--- prnt/hpijs/hpijsfax.cpp.orig	Sat Apr  1 16:35:53 2006
+++ prnt/hpijs/hpijsfax.cpp	Sat Apr  1 16:37:36 2006
@@ -297,8 +297,8 @@
 
 	memset (&tv, 0, sizeof (tv));
 	gettimeofday (&tv, NULL);
-	cur_time = localtime (&tv.tv_sec);
-    memset (hpFileName, 0, 256);
+	cur_time = localtime ((const time_t *)&tv.tv_sec);
+	memset (hpFileName, 0, 256);
 	sprintf (hpFileName, "%s/hplipfax%d%d%d%d%d%d.g3", getenv ("TMPDIR"),
 						  cur_time->tm_year+1900, cur_time->tm_mon+1, cur_time->tm_mday,
 						  cur_time->tm_hour, cur_time->tm_min, cur_time->tm_sec);
