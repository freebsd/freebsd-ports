--- ./libs/libmyth/util.cpp.orig	2008-02-24 10:19:20.000000000 -0500
+++ ./libs/libmyth/util.cpp	2009-02-23 09:59:26.000000000 -0500
@@ -54,6 +54,10 @@
 #include <sys/mount.h>  // for struct statfs
 #endif
 
+#if defined(__FreeBSD__)
+#include <sys/mount.h>	// for struct statfs
+#endif
+
 #ifdef USE_LIRC
 #include "lircevent.h"
 #endif
