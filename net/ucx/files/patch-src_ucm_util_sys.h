--- src/ucm/util/sys.h.orig	2026-02-04 09:52:46 UTC
+++ src/ucm/util/sys.h
@@ -108,7 +108,7 @@ void *ucm_brk_syscall(void *addr);
 /**
  * @return System thread id of the current thread.
  */
-pid_t ucm_get_tid();
+pid_t ucm_get_tid(void);
 
 
 /**
