Index: ev_signal.c
diff -u ev_signal.c.orig ev_signal.c
--- ev_signal.c.orig	Thu Sep  7 05:28:36 2000
+++ ev_signal.c	Sun Nov 18 08:58:10 2001
@@ -94,7 +94,7 @@
 		SIGINT, ev_signal_initiator_generic, ev_handler_cleanup
 	},
 	{
-		SIGHUP, ev_signal_initiator_generic, ev_handler_cleanup
+		SIGHUP, SIG_IGN, NULL
 	},
 	{
 		SIGTERM, ev_signal_initiator_generic, ev_handler_cleanup
