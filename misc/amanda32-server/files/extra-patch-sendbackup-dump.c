--- client-src/sendbackup-dump.c.orig	2008-12-13 04:18:11.000000000 +0900
+++ client-src/sendbackup-dump.c	2009-01-27 07:30:40.000000000 +0900
@@ -35,6 +35,10 @@
 #include "clock.h"
 #include "version.h"
 
+#ifdef __FreeBSD__
+#include <sys/param.h>
+#endif
+
 #define LEAF_AND_DIRS "sed -e \'\ns/^leaf[ \t]*[0-9]*[ \t]*\\.//\nt\n/^dir[ \t]/ {\ns/^dir[ \t]*[0-9]*[ \t]*\\.//\ns%$%/%\nt\n}\nd\n\'"
 
 static amregex_t re_table[] = {
@@ -310,6 +314,9 @@
 			    cmdX, config,
 			    "vxdump",
 			    dumpkeys,
+#ifdef __FreeBSD__
+			    "64",
+#endif
 			    "1048576",
 			    "-",
 			    device,
