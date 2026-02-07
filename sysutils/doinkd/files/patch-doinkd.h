--- doinkd.h.orig	2006-05-29 23:52:32.000000000 -0700
+++ doinkd.h	2012-05-01 15:58:36.200762985 -0700
@@ -1,11 +1,20 @@
 #include <sys/types.h>
 #include <stdio.h>
 #include <sys/param.h>
+#if defined(__FreeBSD_version) && __FreeBSD_version >= 900007
+#define HAVE_UTMPX
+#else
 #include <utmp.h>
+#endif
+
 
+#if defined(__FreeBSD_version) && __FreeBSD_version < 900007
 #define qelem qelem_sys	/* Work around to use our own qelem below */
+#endif
 #include <stdlib.h>
+#if defined(__FreeBSD_version) && __FreeBSD_version < 900007
 #undef qelem
+#endif
 
 #ifdef HAVE_UTMPX
 #include <utmpx.h>
