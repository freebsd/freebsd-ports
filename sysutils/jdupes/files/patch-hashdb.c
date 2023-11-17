--- hashdb.c.orig	2023-08-27 01:12:34 UTC
+++ hashdb.c
@@ -31,6 +31,7 @@ static hashdb_t *hashdb[HT_SIZE];
 static int hashdb_init = 0;
 static int hashdb_algo = 0;
 static int hashdb_dirty = 0;
+static int new_hashdb = 0;
 
 /* Pivot direction for rebalance */
 enum pivot { PIVOT_LEFT, PIVOT_RIGHT };
@@ -68,20 +69,35 @@ int save_hash_database(const char * const restrict dbn
 {
   FILE *db = NULL;
   uint64_t cnt = 0;
+  char *dbtemp;
 
   if (dbname == NULL) goto error_hashdb_null;
   LOUD(fprintf(stderr, "save_hash_database('%s')\n", dbname);)
   /* Don't save the hash database if it wasn't changed */
   if (hashdb_dirty == 0 && destroy == 0) return 0;
   if (hashdb_dirty == 1) {
+
     errno = 0;
-    db = fopen(dbname, "w+b");
+    dbtemp = malloc(strlen(dbname) + 5);
+    if (dbtemp == NULL) goto error_hashdb_alloc;
+    strcpy(dbtemp, dbname);
+    strcat(dbtemp, ".tmp");
+    /* Try to remove any existing temporary database, ignoring errors */
+    remove(dbtemp);
+    db = fopen(dbtemp, "rb");
     if (db == NULL) goto error_hashdb_open;
   }
 
-  if (write_hashdb_entry(db, NULL, &cnt, destroy) != 0) goto error_hashdb_write;
   if (hashdb_dirty == 1) {
+    if (write_hashdb_entry(db, NULL, &cnt, destroy) != 0) goto error_hashdb_write;
     fclose(db);
+    if (new_hashdb == 0) {
+      errno = 0;
+      if (remove(dbname) != 0) {
+        if (errno != ENOENT) goto error_hashdb_remove;
+      }
+    }
+    if (rename(dbtemp, dbname) != 0) goto error_hashdb_rename;
     LOUD(if (hashdb_dirty == 1) fprintf(stderr, "Wrote %" PRIu64 " items to hash databse '%s'\n", cnt, dbname);)
     hashdb_dirty = 0;
   }
@@ -92,12 +108,22 @@ error_hashdb_null:
   fprintf(stderr, "error: internal failure: NULL pointer for hashdb\n");
   return -1;
 error_hashdb_open:
-  fprintf(stderr, "error: cannot open hashdb '%s' for writing: %s\n", dbname, strerror(errno));
+  fprintf(stderr, "error: cannot open temp hashdb '%s' for writing: %s\n", dbtemp, strerror(errno));
   return -2;
 error_hashdb_write:
-  fprintf(stderr, "error: writing failed to hashdb '%s': %s\n", dbname, strerror(errno));
+  fprintf(stderr, "error: write failed to temp hashdb '%s': %s\n", dbtemp, strerror(errno));
   fclose(db);
   return -3;
+error_hashdb_alloc:
+  fprintf(stderr, "error: cannot allocate memory for temporary hashdb name\n");
+  return -4;
+error_hashdb_remove:
+  fprintf(stderr, "error: cannot delete old hashdb '%s': %s\n", dbname, strerror(errno));
+  remove(dbtemp);
+  return -5;
+error_hashdb_rename:
+  fprintf(stderr, "error: cannot rename temporary hashdb '%s' to '%s'; leaving it alone: %s\n", dbtemp, dbname, strerror(errno));
+  return -6;
 }
 
 
@@ -435,31 +461,40 @@ int64_t load_hash_database(char *dbname)
     entry->hashcount = hashcount;
   }
 
+  fclose(db);
   return linenum - 1;
 
 warn_hashdb_open:
   fprintf(stderr, "Creating a new hash database '%s'\n", dbname);
+  fclose(db);
+  new_hashdb = 1;
   return 0;
 error_hashdb_read:
   fprintf(stderr, "error reading hash database '%s': %s\n", dbname, strerror(errno));
+  fclose(db);
   return -1;
 error_hashdb_header:
   fprintf(stderr, "error in header of hash database '%s'\n", dbname);
+  fclose(db);
   return -2;
 error_hashdb_version:
   fprintf(stderr, "error: bad db version %u in hash database '%s'\n", db_ver, dbname);
+  fclose(db);
   return -3;
 error_hashdb_line:
   fprintf(stderr, "\nerror: bad line %" PRId64 " in hash database '%s':\n\n%s\n\n", linenum, dbname, line);
+  fclose(db);
   return -4;
 error_hashdb_add:
   fprintf(stderr, "error: internal failure allocating a hashdb entry\n");
+  fclose(db);
   return -5;
 error_hashdb_null:
   fprintf(stderr, "error: internal failure: NULL pointer for hashdb\n");
   return -6;
 warn_hashdb_algo:
   fprintf(stderr, "warning: hashdb uses a different hash algorithm than selected; not loading\n");
+  fclose(db);
   return -7;
 }
  
