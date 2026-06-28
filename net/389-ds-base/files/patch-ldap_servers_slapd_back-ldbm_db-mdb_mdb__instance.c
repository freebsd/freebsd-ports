--- ldap/servers/slapd/back-ldbm/db-mdb/mdb_instance.c.orig	2026-06-28 11:12:50 UTC
+++ ldap/servers/slapd/back-ldbm/db-mdb/mdb_instance.c
@@ -368,9 +368,20 @@ add_index_dbi(caddr_t attr, caddr_t otx)
 }
 
 /* Destructor for dbi's tree */
-void free_dbi_node(void *node)
+static void
+dbmdb_tree_destroy(dbmdb_ctx_t *ctx)
 {
-    /* as the tree points on ctx->dbi_slots slots, there is nothing to do here */
+    int i;
+
+    for (i = 0; i < ctx->startcfg.max_dbs; i++) {
+        if (ctx->dbi_slots[i].dbname != NULL) {
+            (void)tdelete(&ctx->dbi_slots[i],
+                          &ctx->dbis_treeroot,
+                          cmp_dbi_names);
+        }
+    }
+
+    ctx->dbis_treeroot = NULL;
 }
 
 /* Open/creat all the dbis to avoid opening the db in operation towards this backend
@@ -511,8 +522,7 @@ error:
     }
     if (rc) {
         /* Roll back invalid slots and rebuild dbis tree */
-        tdestroy(ctx->dbis_treeroot, free_dbi_node);
-        ctx->dbis_treeroot = NULL;
+        dbmdb_tree_destroy(ctx);
         for (i=0; i < ctx->startcfg.max_dbs; i++) {
             if (ctx->dbi_slots[i].dbname) {
                 if (valid_slots[i]) {
@@ -791,8 +801,7 @@ void dbmdb_ctx_close(dbmdb_ctx_t *ctx)
         ctx->env = NULL;
     }
     if (ctx->dbi_slots) {
-        tdestroy(ctx->dbis_treeroot, free_dbi_node);
-        ctx->dbis_treeroot = NULL;
+        dbmdb_tree_destroy(ctx);
         for (i=0; i<ctx->startcfg.max_dbs; i++)
             slapi_ch_free((void**)&ctx->dbi_slots[i].dbname);
         slapi_ch_free((void**)&ctx->dbi_slots);
