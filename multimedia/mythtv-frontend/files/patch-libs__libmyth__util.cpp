--- ./libs/libmyth/util.cpp.orig	2008-02-24 10:19:20.000000000 -0500
+++ ./libs/libmyth/util.cpp	2009-04-22 21:05:20.000000000 -0400
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
