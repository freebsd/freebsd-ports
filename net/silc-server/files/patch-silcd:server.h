--- silcd/server.h.orig	Mon Oct 22 23:41:38 2001
+++ silcd/server.h	Sat Nov 10 12:02:26 2001
@@ -121,6 +121,7 @@ int silc_server_alloc(SilcServer *new_se
 void silc_server_free(SilcServer server);
 int silc_server_init(SilcServer server);
 void silc_server_daemonise(SilcServer server);
+void silc_server_drop(SilcServer server);
 void silc_server_run(SilcServer server);
 void silc_server_stop(SilcServer server);
 void silc_server_start_key_exchange(SilcServer server,
