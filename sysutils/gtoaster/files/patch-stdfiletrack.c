
$FreeBSD$

--- stdfiletrack.c.orig
+++ stdfiletrack.c
@@ -21,7 +21,12 @@
 #include "dependencies.h"
 
 #ifndef __svr4__
+#include <osreldate.h>
+#if __FreeBSD_version >= 600007
+void swab(const void *from,void *to,ssize_t n);
+#else
 void swab(const void *from,void *to,size_t n);
+#endif
 #endif
 
 #include "tracks.h"
