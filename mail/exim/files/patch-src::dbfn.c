--- src/dbfn.c.orig	Wed Dec 18 12:28:01 2002
+++ src/dbfn.c	Tue Jan 21 12:17:02 2003
@@ -148,7 +148,7 @@
 sprintf(CS buffer, "%s/db/%s", spool_directory, name);
 EXIM_DBOPEN(buffer, flags, EXIMDB_MODE, &(dbblock->dbptr));
 
-if (dbblock->dbptr == NULL && errno == ENOENT)
+if (dbblock->dbptr == NULL && errno == ENOENT && flags == O_RDWR)
   {
   DEBUG(D_hints_lookup)
     debug_printf("%s appears not to exist: trying to create\n", buffer);
