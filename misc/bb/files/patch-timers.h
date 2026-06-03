--- timers.h.orig	2001-04-26 15:04:22 UTC
+++ timers.h
@@ -49,8 +49,8 @@ void tl_allegromode (int mode);	/*Just for djgpp */
 extern tl_group *syncgroup, *asyncgroup;
 void tl_sleep (int);
 void tl_allegromode (int mode);	/*Just for djgpp */
-int tl_lookup_timer (tl_timer * t) REGISTERS (3);
-void tl_reset_timer (tl_timer * t) REGISTERS (3);
+int tl_lookup_timer (tl_timer * t);
+void tl_reset_timer (tl_timer * t);
 
 struct timeemulator *tl_create_emulator(void);
 void tl_free_emulator(struct timeemulator *t);
