--- src/lib/memusage.c.orig	2021-10-27 02:46:02 UTC
+++ src/lib/memusage.c
@@ -535,25 +535,25 @@ memusage_set_stack_accounting(memusage_t *mu, bool on)
 	MEMUSAGE_THREAD_UNLOCK(mu);
 }
 
-struct callframe {
+struct callframes {
 	size_t calls;
 	const struct stackatom *frame;
 	const struct memusage_counter *mc;
 };
 
 /**
- * qsort() callback for sorting callframe items by decreasing call amount.
+ * qsort() callback for sorting callframes items by decreasing call amount.
  */
 static int
 callframe_cmp(const void *p1, const void *p2)
 {
-	const struct callframe *f1 = p1, *f2 = p2;
+	const struct callframes *f1 = p1, *f2 = p2;
 
 	return CMP(f2->calls, f1->calls);	/* Decreasing order */
 }
 
 struct callframe_filler {
-	struct callframe *array;
+	struct callframes *array;
 	size_t capacity;
 	size_t count;
 	const memusage_t *mu;
@@ -568,7 +568,7 @@ callframe_filler_add(const void *key, void *value, voi
 {
 	struct callframe_filler *filler = data;
 	struct memusage_counter *mc = value;
-	struct callframe *f;
+	struct callframes *f;
 
 	memusage_counter_check(mc);
 	g_assert(filler->count < filler->capacity);
@@ -648,7 +648,7 @@ memusage_sort_frames(const memusage_t *mu, bool period
 static void
 memusage_sorted_frame_dump_log(logagent_t *la, const memusage_t *mu,
 	const char *name, const char *what,
-	struct callframe *array, size_t count, hash_table_t *all, size_t recurses)
+	struct callframes *array, size_t count, hash_table_t *all, size_t recurses)
 {
 	size_t i;
 	const char *event;
@@ -664,7 +664,7 @@ memusage_sorted_frame_dump_log(logagent_t *la, const m
 	event = (0 == mu->width) ? "size" : "calls";
 
 	for (i = 0; i < count; i++) {
-		struct callframe *cf = &array[i];
+		struct callframes *cf = &array[i];
 		struct memusage_counter *mc;
 		size_t total;
 
