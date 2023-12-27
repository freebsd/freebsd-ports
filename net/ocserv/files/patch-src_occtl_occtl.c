--- src/occtl/occtl.c.orig	2023-12-17 10:19:23 UTC
+++ src/occtl/occtl.c
@@ -260,7 +260,7 @@ static int handle_help_cmd(CONN_TYPE * conn, const cha
 static int handle_reset_cmd(CONN_TYPE * conn, const char *arg, cmd_params_st *params)
 {
 	rl_reset_terminal(NULL);
-#ifdef HAVE_ORIG_READLINE
+#if defined(HAVE_ORIG_READLINE) && !defined(__FreeBSD__)
 	rl_reset_screen_size();
 #endif
 
