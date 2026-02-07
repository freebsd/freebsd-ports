--- imap/jmap_mailbox.c.orig	2024-03-18 02:20:35 UTC
+++ imap/jmap_mailbox.c
@@ -1327,7 +1327,7 @@ static int _mboxquery_run(mboxquery_t *query, const mb
 
     /* Apply comparators */
     cyr_qsort_r(query->result.data, query->result.count, sizeof(void*),
-                (int(*)(const void*, const void*, void*)) _mboxquery_compar, query);
+                (int(*)QSORT_R_COMPAR_ARGS(const void*, const void*, void*)) _mboxquery_compar, query);
 
     /* Build in-memory tree */
     hash_table recs_by_parentid = HASH_TABLE_INITIALIZER;
