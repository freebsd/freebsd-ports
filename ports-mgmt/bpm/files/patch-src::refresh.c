--- src/refresh.c.orig	Tue Aug 24 15:18:57 2004
+++ src/refresh.c	Tue Aug 24 15:20:12 2004
@@ -62,7 +62,11 @@
 __RCSID("$Id: refresh.c,v 1.32 2004/08/24 02:40:08 sethk Exp $");
 
 /* XXX use libinstall/lib.h */
+#if __FreeBSD_version >= 500036
+#define	INDEX_FN    PORTS_BASE "/INDEX-5"
+#else
 #define	INDEX_FN    PORTS_BASE "/INDEX"
+#endif
 #define INDEX_MAXLN 4096
 #define DB_DIR	    "/var/db/pkg"
 #define ITER_BYTES  (128 * 1024)
