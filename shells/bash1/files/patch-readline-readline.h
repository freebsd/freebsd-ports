--- lib/readline/readline.h.orig	Fri Aug 29 12:33:32 2003
+++ lib/readline/readline.h	Fri Aug 29 12:31:34 2003
@@ -271,7 +271,8 @@
 
 /* Functions in display.c */
 extern void rl_redisplay ();
-extern int rl_message (), rl_clear_message ();
+extern int rl_message (char *, ...);
+extern int rl_clear_message ();
 extern int rl_reset_line_state ();
 extern int rl_character_len ();
 extern int rl_show_char ();
