--- spa/plugins/support/loop.c.orig	2024-07-12 07:24:23 UTC
+++ spa/plugins/support/loop.c
@@ -1157,7 +1157,7 @@ impl_init(const struct spa_handle_factory *factory,
 		goto error_exit_free_poll;
 	}
 
-	if (tss_create(&impl->queue_tss_id, (tss_dtor_t)loop_queue_destroy) != 0) {
+	if (tss_create(&impl->queue_tss_id, (tss_dtor_t)loop_queue_destroy) != thrd_success) {
 		res = -errno;
 		spa_log_error(impl->log, "%p: can't create tss: %m", impl);
 		goto error_exit_free_wakeup;
