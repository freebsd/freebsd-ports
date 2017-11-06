--- src/amdgpu_drm_queue.c.orig	2016-09-20 08:19:15 UTC
+++ src/amdgpu_drm_queue.c
@@ -61,7 +61,7 @@ amdgpu_drm_queue_handler(int fd, unsigne
 			 unsigned int usec, void *user_ptr)
 {
 	uintptr_t seq = (uintptr_t)user_ptr;
-	struct amdgpu_drm_queue_entry *e, *tmp;
+	struct amdgpu_drm_queue_entry *e = NULL, *tmp;
 
 	xorg_list_for_each_entry_safe(e, tmp, &amdgpu_drm_queue, list) {
 		if (e->seq == seq) {
@@ -133,7 +133,7 @@ amdgpu_drm_abort_one(struct amdgpu_drm_q
 void
 amdgpu_drm_abort_client(ClientPtr client)
 {
-	struct amdgpu_drm_queue_entry *e;
+	struct amdgpu_drm_queue_entry *e = NULL;
 
 	xorg_list_for_each_entry(e, &amdgpu_drm_queue, list) {
 		if (e->client == client)
@@ -147,7 +147,7 @@ amdgpu_drm_abort_client(ClientPtr client
 void
 amdgpu_drm_abort_entry(uintptr_t seq)
 {
-	struct amdgpu_drm_queue_entry *e, *tmp;
+	struct amdgpu_drm_queue_entry *e = NULL, *tmp;
 
 	xorg_list_for_each_entry_safe(e, tmp, &amdgpu_drm_queue, list) {
 		if (e->seq == seq) {
@@ -163,7 +163,7 @@ amdgpu_drm_abort_entry(uintptr_t seq)
 void
 amdgpu_drm_abort_id(uint64_t id)
 {
-	struct amdgpu_drm_queue_entry *e, *tmp;
+	struct amdgpu_drm_queue_entry *e = NULL, *tmp;
 
 	xorg_list_for_each_entry_safe(e, tmp, &amdgpu_drm_queue, list) {
 		if (e->id == id) {
@@ -191,7 +191,7 @@ amdgpu_drm_queue_init()
 void
 amdgpu_drm_queue_close(ScrnInfoPtr scrn)
 {
-	struct amdgpu_drm_queue_entry *e, *tmp;
+	struct amdgpu_drm_queue_entry *e = NULL, *tmp;
 
 	xorg_list_for_each_entry_safe(e, tmp, &amdgpu_drm_queue, list) {
 		if (e->crtc->scrn == scrn)
