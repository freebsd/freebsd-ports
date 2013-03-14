commit 6bf8c2d025e30e5635e6648f35ff8dcbc7c4709c
Author: Alexandre Perrin <alexandre.perrin@netoxygen.ch>
Date:   Tue Mar 5 12:04:44 2013 +0100

    check the return value of sqlite3_column_text() against NULL in get_sql_string()
    
    The return value of sqlite3_column_text() was not checked and passed
    directly to strdup() causing a SIGSEV from libc. This patch ensure that
    a NULL returned value will not be given to strdup().

diff --git libpkg/pkgdb.c libpkg/pkgdb.c
index 7140a69..7a2c706 100644
--- libpkg/pkgdb.c
+++ libpkg/pkgdb.c
@@ -2413,8 +2413,11 @@ get_sql_string(sqlite3 *s, const char *sql, char **res)
 
 	ret = sqlite3_step(stmt);
 
-	if (ret == SQLITE_ROW)
-		*res = strdup(sqlite3_column_text(stmt, 0));
+	if (ret == SQLITE_ROW) {
+		const unsigned char *tmp;
+		tmp = sqlite3_column_text(stmt, 0);
+		*res = (tmp == NULL ? NULL : strdup(tmp));
+	}
 
 	if (ret == SQLITE_DONE)
 		*res = NULL;
