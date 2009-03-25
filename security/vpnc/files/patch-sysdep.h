--- sysdep.h.orig	2009-03-25 03:28:26.000000000 -0400
+++ sysdep.h	2009-03-25 03:29:18.000000000 -0400
@@ -86,6 +86,10 @@
 #define HAVE_FGETLN    1
 #define HAVE_UNSETENV  1
 #define HAVE_SETENV    1
+#include <sys/param.h>
+#if __FreeBSD_version >= 800067
+#define	HAVE_GETLINE   1
+#endif
 #endif
 
 /***************************************************************************/
