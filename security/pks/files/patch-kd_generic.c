--- ./kd_generic.c.orig 2024-05-21 01:17:10 UTC
+++ ./kd_generic.c
@@ -325,13 +325,13 @@
 /* create/open/close/sync */
 
 static int
-kd_worddata_compare (DB * db, const DBT * a, const DBT * b)
+kd_worddata_compare (DB * db, const DBT * a, const DBT * b, size_t *locp)
 {
   return (memcmp (b->data, a->data, 12));
 }
 
 static void
-kd_errcall (const char *db_errpfx, char *buffer)
+kd_errcall (const DB_ENV *dbenv, const char *db_errpfx, const char *buffer)
 {
   log_error (db_errpfx ? db_errpfx : "db_errcall", buffer);
 }
@@ -396,7 +396,6 @@
   if (oflags & KD_OPEN_RECOVER)
     {
       appflags |= DB_INIT_LOG | DB_RECOVER | DB_CREATE;
-      dbenv->set_verbose (dbenv, DB_VERB_CHKPOINT, 1);
       dbenv->set_verbose (dbenv, DB_VERB_WAITSFOR, 1);
       dbenv->set_verbose (dbenv, DB_VERB_DEADLOCK, 1);
       dbenv->set_verbose (dbenv, DB_VERB_RECOVERY, 1);
