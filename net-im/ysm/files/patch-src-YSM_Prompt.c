--- src/YSM_Prompt.c.orig	2008-01-12 22:36:41.000000000 +0300
+++ src/YSM_Prompt.c	2008-01-12 22:37:50.000000000 +0300
@@ -564,6 +564,10 @@
 	YSM_ConsoleRestore();
 
 	/* Set default readline values */
+	rl_readline_name = "ysm";
+	using_history();
+	unstifle_history();
+
 	rl_variable_bind("editing-mode", "emacs");
 	rl_bind_key('\t', YSM_ConsoleTabHook);	/* Tab hook for emacs */
 	/* ysm hot keys */
