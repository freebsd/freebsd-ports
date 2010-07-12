--- src/audacious.c.orig
+++ src/audacious.c
@@ -62,7 +62,7 @@ static audacious_t audacious_items;
 /* -----------------------------------------
  * Conky update function for audacious data.
  * ----------------------------------------- */
-void update_audacious(void)
+int update_audacious(void)
 {
 	/* The worker thread is updating audacious_items array asynchronously
 	 * to the main conky thread.
@@ -79,6 +79,7 @@ void update_audacious(void)
 	timed_thread_lock(info.audacious.p_timed_thread);
 	memcpy(&info.audacious.items, audacious_items, sizeof(audacious_items));
 	timed_thread_unlock(info.audacious.p_timed_thread);
+	return 0;
 }
 
 /* ---------------------------------------------------------
