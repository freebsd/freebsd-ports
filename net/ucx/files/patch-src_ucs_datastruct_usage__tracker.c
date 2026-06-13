--- src/ucs/datastruct/usage_tracker.c.orig	2026-05-06 13:47:14 UTC
+++ src/ucs/datastruct/usage_tracker.c
@@ -14,6 +14,7 @@
 #include <ucs/debug/memtrack_int.h>
 #include <ucs/sys/compiler.h>
 #include <ucs/sys/math.h>
+#include <ucs/algorithm/qsort_r.h>
 
 #define UCS_USAGE_TRACKER_VERIFY_SCORE_PARAM(_params, _field) \
     if (((_params)->_field > 1) || ((_params)->_field < 0)) { \
@@ -207,8 +208,8 @@ static void ucs_usage_tracker_promote(ucs_usage_tracke
         elem_index ++;
     )
 
-    qsort_r(elems_array, elems_count, sizeof(*elems_array),
-            ucs_usage_tracker_compare, params);
+    ucs_qsort_r(elems_array, elems_count, sizeof(*elems_array),
+                ucs_usage_tracker_compare, params);
 
     promote_count = ucs_min(params->promote_thresh, elems_count);
     for (elem_index = 0; elem_index < promote_count; ++elem_index) {
