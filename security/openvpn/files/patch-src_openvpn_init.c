--- src/openvpn/init.c.orig	2025-04-02 06:53:10 UTC
+++ src/openvpn/init.c
@@ -330,7 +330,7 @@ management_callback_remote_entry_count(void *arg)
 static unsigned int
 management_callback_remote_entry_count(void *arg)
 {
-    assert(arg);
+    ASSERT(arg);
     struct context *c = (struct context *) arg;
     struct connection_list *l = c->options.connection_list;
 
@@ -340,8 +340,8 @@ management_callback_remote_entry_get(void *arg, unsign
 static bool
 management_callback_remote_entry_get(void *arg, unsigned int index, char **remote)
 {
-    assert(arg);
-    assert(remote);
+    ASSERT(arg);
+    ASSERT(remote);
 
     struct context *c = (struct context *) arg;
     struct connection_list *l = c->options.connection_list;
