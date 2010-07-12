--- src/audacious.h.orig
+++ src/audacious.h
@@ -60,7 +60,7 @@ int create_audacious_thread(void);
 int destroy_audacious_thread(void);
 
 /* Service routine for the conky main thread */
-void update_audacious(void);
+int update_audacious(void);
 
 /* Thread functions */
 void *audacious_thread_func(void *);
