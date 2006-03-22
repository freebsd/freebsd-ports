Index: client-src/sendbackup-dump.c
===================================================================
RCS file: /home/cvs/opensources/amanda/client-src/sendbackup-dump.c,v
retrieving revision 1.1.1.2
retrieving revision 1.5
diff -u -r1.1.1.2 -r1.5
--- client-src/sendbackup-dump.c	25 Jun 2003 04:39:28 -0000	1.1.1.2
+++ client-src/sendbackup-dump.c	25 Jun 2003 04:43:20 -0000	1.5
@@ -40,6 +40,10 @@
 #define NAUGHTY_BITS			/* but then I'd have to kill you */
 #endif
 
+#ifdef __FreeBSD__
+#include <sys/param.h>
+#endif
+
 #define LEAF_AND_DIRS "sed -e \'\ns/^leaf[ \t]*[0-9]*[ \t]*\\.//\nt\n/^dir[ \t]/ {\ns/^dir[ \t]*[0-9]*[ \t]*\\.//\ns%$%/%\nt\n}\nd\n\'"
 
 static regex_t re_table[] = {
@@ -306,6 +310,12 @@
 
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
@@ -328,6 +338,9 @@
 			    &dumpin, &dumpout, &mesgf, 
 			    "dump",
 			    dumpkeys,
+#ifdef __FreeBSD__
+			    "64",
+#endif
 			    "1048576",
 #ifdef HAVE_HONOR_NODUMP
 			    "0",
