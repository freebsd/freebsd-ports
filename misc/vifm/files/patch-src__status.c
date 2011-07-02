--- src/status.c.orig	2011-06-19 22:52:25.000000000 +0900
+++ src/status.c	2011-06-26 15:27:19.000000000 +0900
@@ -41,7 +41,9 @@
 	curr_stats.dirsize_cache = 0;
 	curr_stats.fast_run = 0;
 	curr_stats.errmsg_shown = 0;
+#ifdef HAVE_LIBGTK
 	curr_stats.gtk_available = 0;
+#endif
 }
 
 /* vim: set tabstop=2 softtabstop=2 shiftwidth=2 noexpandtab cinoptions-=(0 : */
