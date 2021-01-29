--- src/occtl/occtl.c.orig	2020-08-06 18:51:31 UTC
+++ src/occtl/occtl.c
@@ -264,7 +264,7 @@ static int handle_help_cmd(CONN_TYPE * conn, const cha
 static int handle_reset_cmd(CONN_TYPE * conn, const char *arg, cmd_params_st *params)
 {
 	rl_reset_terminal(NULL);
-#ifdef HAVE_ORIG_READLINE
+#if defined(HAVE_ORIG_READLINE) && !defined(__FreeBSD__)
 	rl_reset_screen_size();
 #endif
 
