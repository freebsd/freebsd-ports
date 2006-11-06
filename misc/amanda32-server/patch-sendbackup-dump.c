--- client-src/sendbackup-dump.c.orig	Fri Sep  8 13:56:23 2006
+++ client-src/sendbackup-dump.c	Fri Sep  8 13:58:27 2006
@@ -370,6 +370,9 @@
 
 	dumpkeys = vstralloc(level_str,
 			     options->no_record ? "" : "u",
+#ifdef __FreeBSD__
+			     "b",
+#endif
 			     "s",
 #ifdef HAVE_HONOR_NODUMP
 			     "h",
@@ -391,8 +394,10 @@
 	dumppid = pipespawn(cmd, STDIN_PIPE,
 			    &dumpin, &dumpout, &mesgf, 
 			    cmd, config,
-			    "dump",
 			    dumpkeys,
+#ifdef __FreeBSD__
+			    "64",
+#endif
 			    "1048576",
 #ifdef HAVE_HONOR_NODUMP
 			    "0",
