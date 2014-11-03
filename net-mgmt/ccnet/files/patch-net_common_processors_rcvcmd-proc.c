--- net/common/processors/rcvcmd-proc.c.orig	2014-09-02 15:49:07.244090539 -0400
+++ net/common/processors/rcvcmd-proc.c	2014-09-02 15:52:55.749963338 -0400
@@ -221,7 +221,7 @@
     int i;
 
     commands = g_strsplit_set (line, " \t", 10);
-    for (i=0, pcmd = commands; *pcmd; pcmd++)
+    for (i = 0, pcmd = commands; *pcmd; pcmd++)
         i++;
     
     if (i == 0) {
@@ -234,7 +234,6 @@
     if (c == NULL) {
         ccnet_processor_send_response (processor, SC_UNKNONW_CMD, 
                                        SS_UNKNONW_CMD, NULL, 0);
-        return;
     } else
         c->handler (processor, i, commands);
 
@@ -534,7 +533,7 @@
     ret = -1;
 
 out:
-    g_free (addr);
+    g_free (addr_port);
     g_free (role);
     g_free (peer_id);
     if (peer) g_object_unref (peer);
@@ -707,6 +706,7 @@
     if (addr_port) {
         peer = ccnet_peer_manager_add_resolve_peer (
             processor->session->peer_mgr, addr, port);
+        g_free (peer->intend_role);
         peer->intend_role = g_strdup(role);
         ccnet_processor_send_response (processor, SC_OK, SS_OK, NULL, 0);
         ret = 0;
@@ -736,7 +736,7 @@
     ret = -1;
 
 out:
-    g_free (addr);
+    g_free (addr_port);
     g_free (role);
     g_free (peer_id);
     if (peer) g_object_unref (peer);
