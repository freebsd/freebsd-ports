--- compress/misc.c.orig	2012-09-02 23:45:51.000000000 +0000
+++ compress/misc.c	2012-09-02 23:46:13.000000000 +0000
@@ -288,7 +288,7 @@
 	return 1;
 }
 
-uninitialize_common()
+void uninitialize_common()
 {
 	initialize_common_done = 0;
 	return;
