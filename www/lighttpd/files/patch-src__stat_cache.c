#
# Do not remove until http://www.freebsd.org/cgi/query-pr.cgi?pr=kern/21768
# is not applied and release new versions.
#
Index: stat_cache.c
===================================================================
--- src/stat_cache.c	(revision 1006)
+++ src/stat_cache.c	(revision 1008)
@@ -487,6 +487,12 @@
 
 
 	if (S_ISREG(st.st_mode)) {
+		/* fix broken stat/open for symlinks to reg files with appended slash on freebsd,osx */
+		if (name->ptr[name->used-2] == '/') {
+			errno = ENOTDIR;
+			return HANDLER_ERROR;
+		}
+
 		/* try to open the file to check if we can read it */
 		if (-1 == (fd = open(name->ptr, O_RDONLY))) {
 			return HANDLER_ERROR;
