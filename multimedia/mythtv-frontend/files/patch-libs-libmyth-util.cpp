--- libs/libmyth/util.cpp	2008-09-14 23:29:09.000000000 +0200
+++ libs/libmyth/util.cpp	2008-09-14 23:28:01.000000000 +0200
@@ -54,6 +54,10 @@
 #include <sys/mount.h>  // for struct statfs
 #endif
 
+#ifdef __FreeBSD__
+#include <sys/mount.h>
+#endif
+
 #ifdef USE_LIRC
 #include "lircevent.h"
 #endif
