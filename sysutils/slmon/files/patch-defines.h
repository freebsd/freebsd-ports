--- defines.h.orig	Wed Sep 11 19:44:03 2002
+++ defines.h	Wed Jul 21 14:12:16 2004
@@ -21,6 +21,7 @@
 #ifndef SLMON_DEFINES_H
 #define SLMON_DEFINES_H
 
+#include <sys/types.h>
 #include <stdlib.h>
 #include <time.h>
 #include <string.h>
@@ -47,7 +48,6 @@
 #include <glibtop/procmap.h>
 #include <glibtop/mountlist.h>
 #include <glibtop/fsusage.h>
-#include <glibtop/xmalloc.h>
 
 #ifndef PROFILE_COUNT
 #define PROFILE_COUNT   1000
