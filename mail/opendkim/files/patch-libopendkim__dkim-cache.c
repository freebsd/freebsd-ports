diff --git a/libopendkim/dkim-cache.c b/libopendkim/dkim-cache.c
index 1bb10e8..3a0d6c5 100644
--- ./libopendkim/dkim-cache.c
+++ ./libopendkim/dkim-cache.c
@@ -508,7 +508,13 @@ dkim_cache_stats(DB *db, u_int *queries, u_int *hits, u_int *expired,
 #if DB_VERSION_CHECK(2,0,0)
 		DB_HASH_STAT *sp;
 
+# if DB_VERSION_CHECK(4,3,0)
 		if (db->stat(db, NULL, (void *) &sp, 0) != 0)
+# elif DB_VERSION_CHECK(4,0,0)
+		if (db->stat(db, (void *) &sp, 0) != 0)
+# else /* DB_VERSION_CHECK(4,0,0) */
+		if (db->stat(db, (void *) &sp, NULL, 0) != 0)
+# endif /* DB_VERSION_CHECK(4,0,0) */
 		{
 			*keys = (u_int) -1;
 		}
