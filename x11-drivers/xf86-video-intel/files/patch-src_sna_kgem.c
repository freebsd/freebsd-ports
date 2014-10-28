--- src/sna/kgem.c.orig	2013-08-04 11:10:59.000000000 +0200
+++ src/sna/kgem.c	2013-08-14 11:59:14.787060294 +0200
@@ -25,6 +25,7 @@
  *
  */
 
+#define _WITH_GETLINE
 #ifdef HAVE_CONFIG_H
 #include "config.h"
 #endif
@@ -1890,7 +1891,8 @@
 static struct kgem_bo *
 search_snoop_cache(struct kgem *kgem, unsigned int num_pages, unsigned flags)
 {
-	struct kgem_bo *bo, *first = NULL;
+	struct kgem_bo *bo = NULL;
+	struct kgem_bo *first = NULL;
 
 	DBG(("%s: num_pages=%d, flags=%x\n", __FUNCTION__, num_pages, flags));
 
@@ -2104,7 +2106,8 @@
 
 static bool kgem_retire__flushing(struct kgem *kgem)
 {
-	struct kgem_bo *bo, *next;
+	struct kgem_bo *bo = NULL;
+	struct kgem_bo *next;
 	bool retired = false;
 
 	list_for_each_entry_safe(bo, next, &kgem->flushing, request) {
@@ -2309,7 +2312,8 @@
 static void kgem_commit(struct kgem *kgem)
 {
 	struct kgem_request *rq = kgem->next_request;
-	struct kgem_bo *bo, *next;
+	struct kgem_bo *bo = NULL;
+	struct kgem_bo *next;
 
 	list_for_each_entry_safe(bo, next, &rq->buffers, request) {
 		assert(next->request.prev == &bo->request);
@@ -2390,7 +2394,8 @@
 
 static void kgem_finish_buffers(struct kgem *kgem)
 {
-	struct kgem_buffer *bo, *next;
+	struct kgem_buffer *bo = NULL;
+	struct kgem_buffer *next;
 
 	list_for_each_entry_safe(bo, next, &kgem->batch_buffers, base.list) {
 		DBG(("%s: buffer handle=%d, used=%d, exec?=%d, write=%d, mmapped=%s\n",
@@ -3252,7 +3257,8 @@
 static struct kgem_bo *
 search_linear_cache(struct kgem *kgem, unsigned int num_pages, unsigned flags)
 {
-	struct kgem_bo *bo, *first = NULL;
+	struct kgem_bo *bo = NULL;
+	struct kgem_bo *first = NULL;
 	bool use_active = (flags & CREATE_INACTIVE) == 0;
 	struct list *cache;
 
@@ -3855,7 +3861,7 @@
 			       uint32_t flags)
 {
 	struct list *cache;
-	struct kgem_bo *bo;
+	struct kgem_bo *bo = NULL;
 	uint32_t pitch, tiled_height, size;
 	uint32_t handle;
 	int i, bucket, retry;
@@ -5302,7 +5308,7 @@
 void kgem_clear_dirty(struct kgem *kgem)
 {
 	struct list * const buffers = &kgem->next_request->buffers;
-	struct kgem_bo *bo;
+	struct kgem_bo *bo = NULL;
 
 	list_for_each_entry(bo, buffers, request) {
 		if (!bo->gpu_dirty)
@@ -5578,7 +5584,7 @@
 				   uint32_t size, uint32_t flags,
 				   void **ret)
 {
-	struct kgem_buffer *bo;
+	struct kgem_buffer *bo = NULL;
 	unsigned offset, alloc;
 	struct kgem_bo *old;
 
