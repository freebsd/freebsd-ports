--- src/search.c.orig	Thu Dec  6 23:52:35 2001
+++ src/search.c	Fri Dec  7 00:05:49 2001
@@ -13,6 +13,7 @@
 #include "dialog-filters.h"
 #include "routing.h"
 #include "autodownload.h"
+#include "hosts.h"
 
 #define MAKE_CODE(a,b,c,d) ( \
 	((guint32) (a) << 24) | \
@@ -1258,7 +1259,8 @@
 		if (
 			sch->items >= search_max_results ||
 			search_result_is_dup(sch, rc) ||
-			!filter_record(sch, rc)
+			!filter_record(sch, rc) ||
+			!check_valid_host(rc->results_set->ip,6346)
 		) {
 			rs->records = g_slist_remove(rs->records, rc);
 			rs->num_recs--;
