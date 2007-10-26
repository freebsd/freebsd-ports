--- prnt/hpijs/hpijsfax.cpp.orig	Sat Oct  6 11:33:52 2007
+++ prnt/hpijs/hpijsfax.cpp	Sun Oct  7 15:06:23 2007
@@ -295,7 +295,7 @@
 
 	memset (&tv, 0, sizeof (tv));
 	gettimeofday (&tv, NULL);
-	cur_time = localtime (&tv.tv_sec);
+	cur_time = localtime((const time_t *)&tv.tv_sec);
     memset (hpFileName, 0, 256);
 	sprintf (hpFileName, "%s/hplipfax%d%d%d%d%d%d.g3", getenv ("TMPDIR"),
 						  cur_time->tm_year+1900, cur_time->tm_mon+1, cur_time->tm_mday,
