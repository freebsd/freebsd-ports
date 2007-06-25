--- src/pkgobject.h.orig	Sat Jun 18 07:29:56 2005
+++ src/pkgobject.h	Mon Jun 25 01:20:20 2007
@@ -31,12 +31,16 @@
 
 #include "pkgquery.h"
 
+#ifndef PORTS_DIR
 #define PORTS_DIR	"/usr/ports/"		/* standard place for the ports dir */
+#endif
 
+#ifndef INDEXFILE
 #if (defined __FreeBSD__) && (__FreeBSD_version >= 500036)
 #define INDEXFILE	PORTS_DIR"INDEX-5"  /* this is kind of weird but thats the way it's done on FreeBSD */
 #else
 #define INDEXFILE	PORTS_DIR"INDEX"    /* where is the INDEX File located? */
+#endif
 #endif
 
 #ifdef __OpenBSD__
