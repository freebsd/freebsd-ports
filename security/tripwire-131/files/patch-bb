--- src/dbase.build.c.orig	Tue May  4 17:31:00 1999
+++ src/dbase.build.c	Tue Jun 13 23:40:06 2000
@@ -60,7 +60,6 @@
 int files_scanned_num = 0;
 
 /* prototypes */
-char *mktemp();
 
 /* new database checking routines */
 static void 	database_record_write();
@@ -135,8 +134,8 @@
 	    die_with_err("malloc() failed in database_build", (char *) NULL);
 	(void) strcpy(tmpfilename, TEMPFILE_TEMPLATE);
 
-	if ((char *) mktemp(tmpfilename) == NULL)
-	    die_with_err("database_build: mktemp()", (char *) NULL);
+	if (mkstemp(tmpfilename) == -1)
+	    die_with_err("database_build: mkstemp()", (char *) NULL);
 
 	(void) strcpy(tempdatabase_file, tmpfilename);
 	(void) strcpy(database, tempdatabase_file);
@@ -814,8 +813,8 @@
     /* build temporary file name */
     (void) strcpy(backup_name, TEMPFILE_TEMPLATE);
 
-    if ((char *) mktemp(backup_name) == NULL) {
-	die_with_err("copy_database_to_backup: mktemp() failed!", NULL);
+    if (mkstemp(backup_name) == -1) {
+	die_with_err("copy_database_to_backup: mkstemp() failed!", NULL);
     }
 
     strcpy (database_backupfile, backup_name);
