--- apps/app_queue.c.orig	2016-03-29 19:25:17 UTC
+++ apps/app_queue.c
@@ -3641,7 +3641,7 @@ static int can_ring_entry(struct queue_e
 		return 0;
 	}
 
-	if (call->member->in_call && call->lastqueue->wrapuptime) {
+	if (call->member->in_call && call->lastqueue && call->lastqueue->wrapuptime) {
 		ast_debug(1, "%s is in call, so not available (wrapuptime %d)\n",
 			call->interface, call->lastqueue->wrapuptime);
 		return 0;
