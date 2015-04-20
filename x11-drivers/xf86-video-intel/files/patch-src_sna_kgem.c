--- src/sna/kgem.c.orig	2013-08-20 20:26:26 UTC
+++ src/sna/kgem.c
@@ -25,6 +25,7 @@
  *
  */
 
+#define _WITH_GETLINE
 #ifdef HAVE_CONFIG_H
 #include "config.h"
 #endif
@@ -1873,7 +1874,8 @@ static void kgem_bo_move_to_snoop(struct
 static struct kgem_bo *
 search_snoop_cache(struct kgem *kgem, unsigned int num_pages, unsigned flags)
 {
-	struct kgem_bo *bo, *first = NULL;
+	struct kgem_bo *bo = NULL;
+	struct kgem_bo *first = NULL;
 
 	DBG(("%s: num_pages=%d, flags=%x\n", __FUNCTION__, num_pages, flags));
 
@@ -2087,7 +2089,8 @@ static bool kgem_retire__buffers(struct 
 
 static bool kgem_retire__flushing(struct kgem *kgem)
 {
-	struct kgem_bo *bo, *next;
+	struct kgem_bo *bo = NULL;
+	struct kgem_bo *next;
 	bool retired = false;
 
 	list_for_each_entry_safe(bo, next, &kgem->flushing, request) {
@@ -2292,7 +2295,8 @@ bool __kgem_ring_is_idle(struct kgem *kg
 static void kgem_commit(struct kgem *kgem)
 {
 	struct kgem_request *rq = kgem->next_request;
-	struct kgem_bo *bo, *next;
+	struct kgem_bo *bo = NULL;
+	struct kgem_bo *next;
 
 	list_for_each_entry_safe(bo, next, &rq->buffers, request) {
 		assert(next->request.prev == &bo->request);
@@ -2373,7 +2377,8 @@ static void kgem_close_inactive(struct k
 
 static void kgem_finish_buffers(struct kgem *kgem)
 {
-	struct kgem_buffer *bo, *next;
+	struct kgem_buffer *bo = NULL;
+	struct kgem_buffer *next;
 
 	list_for_each_entry_safe(bo, next, &kgem->batch_buffers, base.list) {
 		DBG(("%s: buffer handle=%d, used=%d, exec?=%d, write=%d, mmapped=%s\n",
@@ -3254,7 +3259,8 @@ void kgem_cleanup_cache(struct kgem *kge
 static struct kgem_bo *
 search_linear_cache(struct kgem *kgem, unsigned int num_pages, unsigned flags)
 {
-	struct kgem_bo *bo, *first = NULL;
+	struct kgem_bo *bo = NULL;
+	struct kgem_bo *first = NULL;
 	bool use_active = (flags & CREATE_INACTIVE) == 0;
 	struct list *cache;
 
@@ -3867,7 +3873,7 @@ struct kgem_bo *kgem_create_2d(struct kg
 			       uint32_t flags)
 {
 	struct list *cache;
-	struct kgem_bo *bo;
+	struct kgem_bo *bo = NULL;
 	uint32_t pitch, tiled_height, size;
 	uint32_t handle;
 	int i, bucket, retry;
@@ -5337,7 +5343,7 @@ void kgem_bo_sync__gtt(struct kgem *kgem
 void kgem_clear_dirty(struct kgem *kgem)
 {
 	struct list * const buffers = &kgem->next_request->buffers;
-	struct kgem_bo *bo;
+	struct kgem_bo *bo = NULL;
 
 	list_for_each_entry(bo, buffers, request) {
 		if (!bo->gpu_dirty)
@@ -5613,7 +5619,7 @@ struct kgem_bo *kgem_create_buffer(struc
 				   uint32_t size, uint32_t flags,
 				   void **ret)
 {
-	struct kgem_buffer *bo;
+	struct kgem_buffer *bo = NULL;
 	unsigned offset, alloc;
 	struct kgem_bo *old;
 
