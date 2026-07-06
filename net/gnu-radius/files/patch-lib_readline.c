--- lib/readline.c.orig	2025-12-11 11:21:32 UTC
+++ lib/readline.c
@@ -129,7 +129,7 @@ grad_readline_init(char *name,
 		return;
 #ifdef WITH_READLINE
 	rl_readline_name = name;
-	rl_attempted_completion_function = completion_fp;
+	rl_attempted_completion_function = (rl_completion_func_t *) completion_fp;
 	rl_getc_function = grad_getc;
 #endif
 }
