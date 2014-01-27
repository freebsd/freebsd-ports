--- ./compress/misc.c.orig	1999-11-03 20:40:10.000000000 +0000
+++ ./compress/misc.c	2014-01-27 21:40:18.000000000 +0000
@@ -288,7 +288,7 @@
 	return 1;
 }
 
-uninitialize_common()
+void uninitialize_common()
 {
 	initialize_common_done = 0;
 	return;
