--- src/gmdns-txt.c.orig	Fri Jun  4 13:19:40 2004
+++ src/gmdns-txt.c	Fri Jun 18 15:19:04 2004
@@ -78,7 +78,11 @@
 		}
 
 		if (pairlen+i > len) {
+#if GLIB_SIZEOF_LONG == 4
 			g_warning ("invalid record (pair claims to extend beyond the end of the record (%d + %d > len = %d))", pairlen, i, len);
+#else
+			g_warning ("invalid record (pair claims to extend beyond the end of the record (%d + %d > len = %ld))", pairlen, i, len);
+#endif
 			return hash;
 		}
 
@@ -106,6 +110,7 @@
 			return hash;
 		}
 
+		name = g_strndup (work, namelen);
 		value = g_strndup (work + namelen + 1, valuelen);
 
 		if (hash == NULL) {
