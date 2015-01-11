--- modules/ratelimit/ratelimit.c.orig	2015-01-11 11:06:53.000000000 +0100
+++ modules/ratelimit/ratelimit.c	2015-01-11 11:06:58.000000000 +0100
@@ -303,7 +303,7 @@
 int get_num_cpus() {
 	int count = 0;
 
-#if defined (__OS_darwin) || defined (__OS_freebsd)
+#if defined (__OS_darwin)
     int nm[2];
     size_t len;
 
