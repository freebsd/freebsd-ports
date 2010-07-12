--- src/conky.h.orig
+++ src/conky.h
@@ -296,9 +296,7 @@ extern int top_cpu, top_mem, top_time;
 #ifdef IOSTATS
 extern int top_io;
 #endif
-#ifdef __linux__
 extern int top_running;
-#endif
 
 /* defined in conky.c, needed by top.c */
 extern int cpu_separate;
@@ -308,7 +306,7 @@ extern int cpu_separate;
 extern struct information info;
 
 /* defined in users.c */
-void update_users(void);
+int update_users(void);
 void update_user_time(char *tty);
 
 /* defined in conky.c */
