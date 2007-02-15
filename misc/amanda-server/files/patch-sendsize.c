--- client-src/sendsize.c.orig	Thu Feb 15 11:11:39 2007
+++ client-src/sendsize.c	Thu Feb 15 11:12:03 2007
@@ -1190,7 +1190,7 @@
 #  endif
 	dumpkeys = vstralloc(level_str,
 			     PARAM_DUMP_ESTIMATE,
-			     PARAM_DUMP_ESTIMATE,
+			     PARAM_HONOR_NODUMP,
 			     "s", "f", NULL);
 
 #  ifdef HAVE_DUMP_ESTIMATE
