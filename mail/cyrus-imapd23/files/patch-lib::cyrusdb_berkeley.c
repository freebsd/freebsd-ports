Index: lib/cyrusdb_berkeley.c
diff -u -p lib/cyrusdb_berkeley.c.orig lib/cyrusdb_berkeley.c
--- lib/cyrusdb_berkeley.c.orig	2007-02-06 03:43:26.000000000 +0900
+++ lib/cyrusdb_berkeley.c	2007-08-06 23:04:15.000000000 +0900
@@ -176,7 +176,15 @@ static int init(const char *dbdir, int m
 	syslog(LOG_WARNING,
 	       "DBERROR: invalid berkeley_locks_max value, using internal default");
     } else {
+#if DB_VERSION_MAJOR >= 4
+	r = dbenv->set_lk_max_locks(dbenv, opt);
+	if (!r)
+	    r = dbenv->set_lk_max_lockers(dbenv, opt);
+	if (!r)
+	    r = dbenv->set_lk_max_objects(dbenv, opt);
+#else
 	r = dbenv->set_lk_max(dbenv, opt);
+#endif
 	if (r) {
 	    dbenv->err(dbenv, r, "set_lk_max");
 	    syslog(LOG_ERR, "DBERROR: set_lk_max(): %s", db_strerror(r));
