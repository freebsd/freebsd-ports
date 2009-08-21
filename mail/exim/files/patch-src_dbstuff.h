
$FreeBSD$

--- src/dbstuff.h.orig
+++ src/dbstuff.h
@@ -331,7 +331,7 @@
 
 /* EXIM_DBSCAN - returns TRUE if data is returned, FALSE at end */
 #define EXIM_DBSCAN(db, key, data, first, cursor)      \
-       ((db)->seq(db, &key, &data, (first? R_FIRST : 0)) == 0)
+	((db)->seq(db, &key, &data, (first? R_FIRST : R_NEXT)) == 0)
 
 /* EXIM_DBDELETE_CURSOR - terminate scanning operation (null). Make it
 refer to cursor, to keep picky compilers happy. */
