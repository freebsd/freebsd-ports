--- src/tcs/tcs_auth_mgr.c.orig	2016-06-20 15:21:26 UTC
+++ src/tcs/tcs_auth_mgr.c
@@ -108,7 +108,7 @@ void
 auth_mgr_swap_in()
 {
 	if (auth_mgr.overflow[auth_mgr.of_tail] != NULL) {
-		LogDebug("waking up thread %lddd, auth slot has opened", THREAD_ID);
+		LogDebug("waking up thread %ld, auth slot has opened", THREAD_ID);
 		/* wake up the next sleeping thread in order and increment tail */
 		COND_SIGNAL(auth_mgr.overflow[auth_mgr.of_tail]);
 		auth_mgr.overflow[auth_mgr.of_tail] = NULL;
@@ -149,7 +149,7 @@ auth_mgr_swap_out(TCS_CONTEXT_HANDLE hCo
 		auth_mgr.overflow[auth_mgr.of_head] = cond;
 		auth_mgr.of_head = (auth_mgr.of_head + 1) % auth_mgr.overflow_size;
 		/* go to sleep */
-		LogDebug("thread %lddd going to sleep until auth slot opens", THREAD_ID);
+		LogDebug("thread %ld going to sleep until auth slot opens", THREAD_ID);
 		auth_mgr.sleeping_threads++;
 		COND_WAIT(cond, &tcsp_lock);
 		auth_mgr.sleeping_threads--;
@@ -180,7 +180,7 @@ auth_mgr_swap_out(TCS_CONTEXT_HANDLE hCo
 		auth_mgr.of_tail = 0;
 		auth_mgr.overflow[auth_mgr.of_head] = cond;
 		auth_mgr.of_head = (auth_mgr.of_head + 1) % auth_mgr.overflow_size;
-		LogDebug("thread %lddd going to sleep until auth slot opens", THREAD_ID);
+		LogDebug("thread %ld going to sleep until auth slot opens", THREAD_ID);
 		auth_mgr.sleeping_threads++;
 		COND_WAIT(cond, &tcsp_lock);
 		auth_mgr.sleeping_threads--;
