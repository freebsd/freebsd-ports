--- client-src/sendbackup-dump.c.orig	Fri Sep  8 13:09:14 2006
+++ client-src/sendbackup-dump.c	Fri Sep  8 13:15:44 2006
@@ -35,6 +35,10 @@
 #include "clock.h"
 #include "version.h"
 
+#ifdef __FreeBSD__
+#include <sys/param.h>
+#endif
+
 #define LEAF_AND_DIRS "sed -e \'\ns/^leaf[ \t]*[0-9]*[ \t]*\\.//\nt\n/^dir[ \t]/ {\ns/^dir[ \t]*[0-9]*[ \t]*\\.//\ns%$%/%\nt\n}\nd\n\'"
 
 static amregex_t re_table[] = {
@@ -370,6 +374,12 @@
 
 	dumpkeys = vstralloc(level_str,
 			     options->no_record ? "" : "u",
+#ifdef __FreeBSD__
+			     "b",
+#if defined(__FreeBSD_version) && (__FreeBSD_version >= 500043)
+			     "L",
+#endif
+#endif
 			     "s",
 #ifdef HAVE_HONOR_NODUMP
 			     "h",
@@ -392,6 +402,9 @@
 			    &dumpin, &dumpout, &mesgf, 
 			    cmd, config,
 			    dumpkeys,
+#ifdef __FreeBSD__
+			    "64",
+#endif
 			    "1048576",
 #ifdef HAVE_HONOR_NODUMP
 			    "0",
