--- src/sna/kgem.c.orig	2013-03-11 11:19:02.000000000 +0100
+++ src/sna/kgem.c	2013-03-12 12:56:49.452065668 +0100
@@ -658,7 +658,11 @@
 	if (file) {
 		size_t len = 0;
 		char *line = NULL;
+#ifdef __GLIBC__
 		while (getline(&line, &len, file) != -1) {
+#else
+		while ((line = fgetln(file, &len)) != (char *) NULL) {
+#endif
 			int mb;
 			if (sscanf(line, "cache size : %d KB", &mb) == 1) {
 				/* Paranoid check against gargantuan caches */
@@ -1666,7 +1670,8 @@
 static struct kgem_bo *
 search_snoop_cache(struct kgem *kgem, unsigned int num_pages, unsigned flags)
 {
-	struct kgem_bo *bo, *first = NULL;
+	struct kgem_bo *bo = NULL;
+	struct kgem_bo *first = NULL;
 
 	DBG(("%s: num_pages=%d, flags=%x\n", __FUNCTION__, num_pages, flags));
 
@@ -1868,7 +1873,8 @@
 
 static bool kgem_retire__flushing(struct kgem *kgem)
 {
-	struct kgem_bo *bo, *next;
+	struct kgem_bo *bo = NULL;
+	struct kgem_bo *next;
 	bool retired = false;
 
 	list_for_each_entry_safe(bo, next, &kgem->flushing, request) {
@@ -2073,7 +2079,8 @@
 static void kgem_commit(struct kgem *kgem)
 {
 	struct kgem_request *rq = kgem->next_request;
-	struct kgem_bo *bo, *next;
+	struct kgem_bo *bo = NULL;
+	struct kgem_bo *next;
 
 	list_for_each_entry_safe(bo, next, &rq->buffers, request) {
 		assert(next->request.prev == &bo->request);
@@ -2154,7 +2161,8 @@
 
 static void kgem_finish_buffers(struct kgem *kgem)
 {
-	struct kgem_buffer *bo, *next;
+	struct kgem_buffer *bo = NULL;
+	struct kgem_buffer *next;
 
 	list_for_each_entry_safe(bo, next, &kgem->batch_buffers, base.list) {
 		DBG(("%s: buffer handle=%d, used=%d, exec?=%d, write=%d, mmapped=%d\n",
@@ -2963,7 +2971,8 @@
 static struct kgem_bo *
 search_linear_cache(struct kgem *kgem, unsigned int num_pages, unsigned flags)
 {
-	struct kgem_bo *bo, *first = NULL;
+	struct kgem_bo *bo = NULL;
+	struct kgem_bo *first = NULL;
 	bool use_active = (flags & CREATE_INACTIVE) == 0;
 	struct list *cache;
 
@@ -3521,7 +3530,7 @@
 			       uint32_t flags)
 {
 	struct list *cache;
-	struct kgem_bo *bo;
+	struct kgem_bo *bo = NULL;
 	uint32_t pitch, tiled_height, size;
 	uint32_t handle;
 	int i, bucket, retry;
@@ -4834,7 +4843,7 @@
 void kgem_clear_dirty(struct kgem *kgem)
 {
 	struct list * const buffers = &kgem->next_request->buffers;
-	struct kgem_bo *bo;
+	struct kgem_bo *bo = NULL;
 
 	list_for_each_entry(bo, buffers, request) {
 		if (!bo->dirty)
@@ -5072,7 +5081,7 @@
 				   uint32_t size, uint32_t flags,
 				   void **ret)
 {
-	struct kgem_buffer *bo;
+	struct kgem_buffer *bo = NULL;
 	unsigned offset, alloc;
 	struct kgem_bo *old;
 
