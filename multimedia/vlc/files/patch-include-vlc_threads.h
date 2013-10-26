--- include/vlc_threads.h.orig  2013-10-22 15:47:18.000000000 +0200
+++ include/vlc_threads.h       2013-10-22 15:48:00.000000000 +0200
@@ -342,13 +342,13 @@
  * Removes a cleanup procedure that was previously registered with
  * vlc_cleanup_push().
  */
-# define vlc_cleanup_pop( ) pthread_cleanup_pop (0)
+# define vlc_cleanup_pop( ) ; pthread_cleanup_pop (0)
 
 /**
  * Removes a cleanup procedure that was previously registered with
  * vlc_cleanup_push(), and executes it.
  */
-# define vlc_cleanup_run( ) pthread_cleanup_pop (1)
+# define vlc_cleanup_run( ) ; pthread_cleanup_pop (1)
 
 #else
 enum
