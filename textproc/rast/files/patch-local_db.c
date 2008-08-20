--- src/local_db.c.orig	2008-08-20 12:45:58.597538000 +0900
+++ src/local_db.c	2008-08-20 12:46:33.000000000 +0900
@@ -2111,7 +2111,7 @@
 
             encoding_module = docs[i]->db->encoding_module;
             tf = APR_RING_FIRST(docs[i]->terms);
-            if (tf == APR_RING_SENTINEL(&docs[i]->terms,
+            if (tf == APR_RING_SENTINEL(docs[i]->terms,
                                         rast_term_frequency_t, link)) {
                 error = get_summary(pool, encoding_module,
                                     summary, summary_nbytes,
