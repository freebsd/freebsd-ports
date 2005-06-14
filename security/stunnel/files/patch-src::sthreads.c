*** src/sthreads.c.old	Mon Jun 13 21:34:53 2005
--- src/sthreads.c	Mon Jun 13 22:15:01 2005
***************
*** 63,68 ****
--- 63,69 ----
  
  static void ctx_cleanup_func(void) { /* cleanup the active thread */
      s_log(LOG_DEBUG, "Context %ld closed", ready_head->id);
+     makecontext(&ctx_cleanup, ctx_cleanup_func, 0);
      s_poll_wait(NULL, 0); /* wait on poll() */
  }
  
