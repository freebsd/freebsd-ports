--- src/ipmishell.c.orig	Sat Jan  8 04:43:38 2005
+++ src/ipmishell.c	Sun Feb  6 23:47:32 2005
@@ -114,7 +114,9 @@
 		rl_event_hook = rl_event_keepalive;
 #if defined(RL_READLINE_VERSION) && RL_READLINE_VERSION >= 0x0402
 		/* set to 1 second */
-		rl_set_keyboard_input_timeout(1000*1000);
+		/* There is a bug in readline 4.2 and later (at least on FreeBSD):
+		 * timeout equal or greater than 1 second causes an infinite loop. */
+		rl_set_keyboard_input_timeout(1000 * 1000 - 1);
 #endif
 	}
 
