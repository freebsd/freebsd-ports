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
@@ -183,10 +187,12 @@
 	if (*sp == '|')
 	    ++i;
 
-    if (i != (PFIELD_NFIELD - 1))
+    if (i < (PFIELD_NFIELD - 1))
     {
 #ifdef DEBUG
-	warnx("invalid number of fields");
+	warnx("invalid number of fields (%d should be %d)",
+		i + 1,
+		PFIELD_NFIELD);
 #endif /* DEBUG */
 	return FALSE;
     }
@@ -320,7 +326,6 @@
 
 	if (_refresh_index_parse(ln, portdp, rdp) != TRUE)
 	{
-	    _refresh_portfree(portdp);
 #ifdef DEBUG
 	    warnx("%s:%u: invalid format", INDEX_FN, rdp->rd_linec);
 #endif /* DEBUG */
