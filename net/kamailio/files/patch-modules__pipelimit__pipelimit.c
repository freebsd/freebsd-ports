--- modules/pipelimit/pipelimit.c.orig	2015-01-11 11:02:38.000000000 +0100
+++ modules/pipelimit/pipelimit.c	2015-01-11 11:02:48.000000000 +0100
@@ -192,7 +192,7 @@
 int get_num_cpus() {
 	int count = 0;
 
-#if defined (__OS_darwin) || defined (__OS_freebsd)
+#if defined (__OS_darwin)
     int nm[2];
     size_t len;
 
