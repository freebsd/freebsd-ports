--- lib/readline.c.orig	2026-03-26 21:35:33 UTC
+++ lib/readline.c
@@ -144,7 +144,7 @@ grad_readline_init(char *name,
 		return;
 #ifdef WITH_READLINE
 	rl_readline_name = name;
-	rl_attempted_completion_function = (CPPFunction *) completion_fp;
+	rl_attempted_completion_function = (rl_completion_func_t *) completion_fp;
 	rl_getc_function = grad_getc;
 #endif
 }
