diff --git src/zfs_arc.c src/zfs_arc.c
index 730d30483b..3ef3e562c7 100644
--- src/zfs_arc.c
+++ src/zfs_arc.c
@@ -188,6 +188,9 @@ static void za_submit_ratio(const char *type_instance, gauge_t hits,
   za_submit_gauge("cache_ratio", type_instance, ratio);
 }
 
+static value_to_rate_state_t arc_hits_state, arc_misses_state, l2_hits_state,
+    l2_misses_state;
+
 static int za_read(void) {
   gauge_t arc_hits, arc_misses, l2_hits, l2_misses;
   kstat_t *ksp = NULL;
@@ -313,14 +316,25 @@ static int za_read(void) {
   za_read_derive(ksp, "mru_hits", "cache_result", "mru-hit");
   za_read_derive(ksp, "mru_ghost_hits", "cache_result", "mru_ghost-hit");
 
+  cdtime_t now = cdtime();
+
   /* Ratios */
-  arc_hits = (gauge_t)get_zfs_value(ksp, "hits");
-  arc_misses = (gauge_t)get_zfs_value(ksp, "misses");
-  l2_hits = (gauge_t)get_zfs_value(ksp, "l2_hits");
-  l2_misses = (gauge_t)get_zfs_value(ksp, "l2_misses");
+  if ((value_to_rate(&arc_hits, (value_t){.derive = get_zfs_value(ksp, "hits")},
+                     DS_TYPE_DERIVE, now, &arc_hits_state) == 0) &&
+      (value_to_rate(&arc_misses,
+                     (value_t){.derive = get_zfs_value(ksp, "misses")},
+                     DS_TYPE_DERIVE, now, &arc_misses_state) == 0)) {
+    za_submit_ratio("arc", arc_hits, arc_misses);
+  }
 
-  za_submit_ratio("arc", arc_hits, arc_misses);
-  za_submit_ratio("L2", l2_hits, l2_misses);
+  if ((value_to_rate(&l2_hits,
+                     (value_t){.derive = get_zfs_value(ksp, "l2_hits")},
+                     DS_TYPE_DERIVE, now, &l2_hits_state) == 0) &&
+      (value_to_rate(&l2_misses,
+                     (value_t){.derive = get_zfs_value(ksp, "l2_misses")},
+                     DS_TYPE_DERIVE, now, &l2_misses_state) == 0)) {
+    za_submit_ratio("L2", l2_hits, l2_misses);
+  }
 
   /* I/O */
   value_t l2_io[] = {
@@ -347,6 +361,11 @@ static int za_init(void) /* {{{ */
   }
 #endif
 
+  memset(&arc_hits_state, 0, sizeof(arc_hits_state));
+  memset(&arc_misses_state, 0, sizeof(arc_misses_state));
+  memset(&l2_hits_state, 0, sizeof(l2_hits_state));
+  memset(&l2_misses_state, 0, sizeof(l2_misses_state));
+
   return (0);
 } /* }}} int za_init */
 
