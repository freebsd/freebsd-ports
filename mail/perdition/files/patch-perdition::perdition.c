--- perdition/perdition.c.orig	Mon Dec  1 02:31:37 2003
+++ perdition/perdition.c	Mon Dec 15 12:07:31 2003
@@ -65,6 +65,14 @@
 #include <dmalloc.h>
 #endif
 
+#include <sys/param.h>
+#ifdef __FreeBSD__
+# if __FreeBSD_version < 500112
+#   include <machine/limits.h>
+# else
+#   include <sys/limits.h>
+# endif
+#endif
 
 /*Use uname information here and there to idinify this system*/
 struct utsname *system_uname;
