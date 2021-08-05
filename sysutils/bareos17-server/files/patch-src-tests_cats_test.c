--- src/tests/cats_test.c	2020-07-09 12:30:11.000000000 -0500
+++ src/tests/cats_test.c	2021-08-05 12:45:09.726640000 -0500
@@ -388,11 +388,11 @@
    ok(db_sql_query(db, "SELECT VersionId FROM Version",
                    db_int_handler, &j), "SELECT VersionId");
 
-   ok(UPDATE_DB(jcr, db, (char*)"UPDATE Version SET VersionId = 1"),
+   ok(UPDATE_DB(jcr, (char*)"UPDATE Version SET VersionId = 1"),
       "Update VersionId");
    nok(check_tables_version(jcr, db), "Check table version");
    Mmsg(buf, "UPDATE Version SET VersionId = %d", j);
-   ok(UPDATE_DB(jcr, db, buf), "Restore VersionId");
+   ok(UPDATE_DB(jcr, db), "Restore VersionId");
 
    if (dbtype != SQL_TYPE_SQLITE3) {
       ok(db_check_max_connections(jcr, db, 1), "Test min Max Connexion");
@@ -444,34 +444,34 @@
    ok(db_sql_query(db, buf, NULL, NULL), "CREATE query");
 
    Mmsg(buf, "INSERT INTO %s (a) VALUES (1)", temp);
-   ok(INSERT_DB(jcr, db, buf), "INSERT query");
-   ok(INSERT_DB(jcr, db, buf), "INSERT query");
+   ok(INSERT_DB(jcr, buf), "INSERT query");
+   ok(INSERT_DB(jcr, buf), "INSERT query");
    ok(sql_affected_rows(db) == 1, "Check sql_affected_rows");
 
    Mmsg(buf, "INSERT INTO aaa%s (a) VALUES (1)", temp);
-   nok(INSERT_DB(jcr, db, buf), "Bad INSERT query");
+   nok(INSERT_DB(jcr, buf), "Bad INSERT query");
    ok(sql_affected_rows(db) == 0, "Check sql_affected_rows");
 
    Mmsg(buf, "UPDATE %s SET a = 2", temp);
-   ok(UPDATE_DB(jcr, db, buf), "UPDATE query");
+   ok(UPDATE_DB(jcr, buf), "UPDATE query");
    ok(sql_affected_rows(db) == 2, "Check sql_affected_rows");
 
    Mmsg(buf, "UPDATE %s SET a = 2 WHERE a = 1", temp);
-   nok(UPDATE_DB(jcr, db, buf), "Empty UPDATE query");
+   nok(UPDATE_DB(jcr, buf), "Empty UPDATE query");
 
    Mmsg(buf, "UPDATE aaa%s SET a = 2", temp);
-   nok(UPDATE_DB(jcr, db, buf), "Bad UPDATE query");
+   nok(UPDATE_DB(jcr, buf), "Bad UPDATE query");
 
    Mmsg(buf, "DELETE FROM %s", temp);
-   ok(DELETE_DB(jcr, db, buf), "DELETE query");
-   nok(DELETE_DB(jcr, db, buf), "Empty DELETE query"); /* TODO bug ? */
+   ok(DELETE_DB(jcr, buf), "DELETE query");
+   nok(DELETE_DB(jcr, buf), "Empty DELETE query"); /* TODO bug ? */
 
    Mmsg(buf, "DELETE FROM aaa%s", temp);
-   ok(DELETE_DB(jcr, db, buf), "Bad DELETE query"); /* TODO bug ? */
+   ok(DELETE_DB(jcr, buf), "Bad DELETE query"); /* TODO bug ? */
 
    Mmsg(buf, "DROP TABLE %s", temp);
-   ok(QUERY_DB(jcr, db, buf), "DROP query");
-   nok(QUERY_DB(jcr, db, buf), "Empty DROP query");
+   ok(QUERY_DB(jcr, buf), "DROP query");
+   nok(QUERY_DB(jcr, buf), "Empty DROP query");
 
    /* ---------------------------------------------------------------- */
 
