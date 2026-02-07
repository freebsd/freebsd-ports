--- imap/jmap_calendar.c.orig	2024-03-18 02:20:35 UTC
+++ imap/jmap_calendar.c
@@ -6962,7 +6962,7 @@ static int eventquery_textsearch_run(jmap_req_t *req,
     if (!expandrecur) {
         struct eventquery_cmp_rock rock = { sort, nsort };
         cyr_qsort_r(matches->data, matches->count, sizeof(void*),
-                    (int(*)(const void*, const void*, void*))eventquery_cmp, &rock);
+                    (int(*)QSORT_R_COMPAR_ARGS(const void*, const void*, void*))eventquery_cmp, &rock);
     }
 
     r = 0;
@@ -9591,7 +9591,7 @@ static void principal_getavailability(jmap_req_t *req,
      * different “busyStatus” properties the server MUST choose the value in
      * the following order: confirmed > unavailable > tentative. */
     cyr_qsort_r(busyperiods->data, busyperiods->count, sizeof(struct busyperiod),
-            (int(*)(const void*, const void*, void*))busyperiod_cmp, NULL);
+            (int(*)QSORT_R_COMPAR_ARGS(const void*, const void*, void*))busyperiod_cmp, NULL);
     int count = dynarray_size(busyperiods) ? 1 : 0;
     int i;
     for (i = 1; i < dynarray_size(busyperiods); i++) {
@@ -9907,7 +9907,7 @@ static void notifsearch_run(const char *userid,
     if (search->sort) {
         cyr_qsort_r(entries->data, entries->count,
                 sizeof(struct notifsearch_entry),
-                (int(*)(const void*, const void*, void*))search->sort,
+                (int(*)QSORT_R_COMPAR_ARGS(const void*, const void*, void*))search->sort,
                 search->sortrock);
     }
 
