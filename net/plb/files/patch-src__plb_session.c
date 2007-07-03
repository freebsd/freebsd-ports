--- ./src/plb_session.c.orig	2003-02-26 22:57:58.000000000 +0800
+++ ./src/plb_session.c	2007-07-03 17:13:15.588392762 +0800
@@ -8,6 +8,8 @@
 # include <dmalloc.h>
 #endif
 
+#define	EVENT_FD_(e) ((e)->ev_fd)
+
 void client_disconnect(Client * const client)
 {
     current_nb_clients--;
@@ -31,19 +33,19 @@
     }
     if (EVENT_FD((&client->server_read_ev)) != -1) {
         event_del(&client->server_read_ev);
-        EVENT_FD((&client->server_read_ev)) = -1;
+        EVENT_FD_((&client->server_read_ev)) = -1;
     }
     if (EVENT_FD((&client->server_write_ev)) != -1) {
         event_del(&client->server_write_ev);
-        EVENT_FD((&client->server_write_ev)) = -1;
+        EVENT_FD_((&client->server_write_ev)) = -1;
     }
     if (EVENT_FD((&client->client_read_ev)) != -1) {
         event_del(&client->client_read_ev);
-        EVENT_FD((&client->client_read_ev)) = -1;
+        EVENT_FD_((&client->client_read_ev)) = -1;
     }
     if (EVENT_FD((&client->client_write_ev)) != -1) {
         event_del(&client->client_write_ev);
-        EVENT_FD((&client->client_write_ev)) = -1;
+        EVENT_FD_((&client->client_write_ev)) = -1;
     }
     if (client->server_fd != -1) {
         while (close(client->server_fd) != 0 && errno == EINTR);
@@ -137,10 +139,10 @@
     client->postbuf_written = (size_t) 0U;    
     client->replybuf_len = (size_t) 0U;
     client->replybuf_written = (size_t) 0U;    
-    EVENT_FD((&client->client_read_ev)) = -1;
-    EVENT_FD((&client->client_write_ev)) = -1;
-    EVENT_FD((&client->server_read_ev)) = -1;
-    EVENT_FD((&client->server_write_ev)) = -1;
+    EVENT_FD_((&client->client_read_ev)) = -1;
+    EVENT_FD_((&client->client_write_ev)) = -1;
+    EVENT_FD_((&client->server_read_ev)) = -1;
+    EVENT_FD_((&client->server_write_ev)) = -1;
     event_set(&client->client_read_ev, client_fd,
               EV_READ, client_read, &clients[client_fd]);
     event_add(&client->client_read_ev, &timeout_header_client_read);
