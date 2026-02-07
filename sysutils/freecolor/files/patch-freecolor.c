--- ./freecolor.c.orig	2014-05-10 02:40:47.870871838 +0100
+++ ./freecolor.c	2014-05-10 02:41:48.220865521 +0100
@@ -148,7 +148,7 @@
 	if (init_called == 0) {
 		init_called = 1;
 
-		sg_init();
+		sg_init(0);
 
 #ifdef HAVE_STATGRAB_DROP_PRIVILEGES
 		/* Drop setuid/setgid privileges. */
@@ -159,8 +159,8 @@
 #endif
 	}
 
-	mem_stats = sg_get_mem_stats();
-	swap_stats = sg_get_swap_stats();
+	mem_stats = sg_get_mem_stats(NULL);
+	swap_stats = sg_get_swap_stats(NULL);
 
 	if (mem_stats == NULL || swap_stats == NULL) {
 		return(-1);
