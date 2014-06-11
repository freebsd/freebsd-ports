commit 4f3ce011ee1d0f00afc8d84ed9fd82cda9f02a08
Author: Bryan Drewery <bryan@shatow.net>
Date:   Wed Jun 11 12:31:21 2014 -0500

    Fix pkgdb_load_rdeps by reverting "Avoid deps full scan when loading dependencies."
    
    This reverts commit cf47e2c24af23c8f278d9c502fe2923a42f23d33.
    
    1. deps should be joined on p.id=d.package_id rather than origin.
       Otherwise no results are returned breaking pkg-query %r, pkg-autoremove,
       etc.
    2. Restore uniqueid support [1]
    
    Discussed with:	bapt [1]
    
    Fixes #833

diff --git libpkg/pkgdb.c libpkg/pkgdb.c
index e46ddeb..7e4500b 100644
--- libpkg/pkgdb.c
+++ libpkg/pkgdb.c
@@ -1923,23 +1923,19 @@ pkgdb_load_rdeps(struct pkgdb *db, struct pkg *pkg)
 {
 	sqlite3_stmt	*stmt = NULL;
 	int		 ret;
-	const char	*origin;
+	const char	*uniqueid;
 	const char	*reponame = NULL;
 	char		 sql[BUFSIZ];
 	const char	*mainsql = ""
 		"SELECT p.name, p.origin, p.version, p.locked "
-		"FROM main.deps AS d "
-		"LEFT JOIN main.packages AS p ON p.origin = d.origin "
+		"FROM main.packages AS p, main.deps AS d "
 		"WHERE p.id = d.package_id "
-		"AND p.name = d.name "
-		"AND d.origin = ?1;";
+			"AND d.name || '~' || d.origin = ?1;";
 	const char	*reposql = ""
 		"SELECT p.name, p.origin, p.version, 0 "
-		"FROM %Q.deps AS d "
-		"LEFT JOIN %Q.packages AS p ON p.origin = d.origin "
+		"FROM %Q.packages AS p, %Q.deps AS d "
 		"WHERE p.id = d.package_id "
-		"AND p.name = d.name "
-		"AND d.origin = ?1;";
+			"AND d.name || '~' || d.origin = ?1;";
 
 	assert(db != NULL && pkg != NULL);
 
@@ -1962,8 +1958,8 @@ pkgdb_load_rdeps(struct pkgdb *db, struct pkg *pkg)
 		return (EPKG_FATAL);
 	}
 
-	pkg_get(pkg, PKG_ORIGIN, &origin);
-	sqlite3_bind_text(stmt, 1, origin, -1, SQLITE_STATIC);
+	pkg_get(pkg, PKG_UNIQUEID, &uniqueid);
+	sqlite3_bind_text(stmt, 1, uniqueid, -1, SQLITE_STATIC);
 
 	while ((ret = sqlite3_step(stmt)) == SQLITE_ROW) {
 		pkg_addrdep(pkg, sqlite3_column_text(stmt, 0),
