--- modules/afsocket/socket-options.c.orig	2020-08-10 18:04:39 UTC
+++ modules/afsocket/socket-options.c
@@ -86,7 +86,16 @@ _setup_keepalive(gint fd)
 static gboolean
 _setup_reuseport(gint fd)
 {
-#ifdef SO_REUSEPORT
+#if defined(SO_REUSEPORT_LB)
+  gint on = 1;
+  if (setsockopt(fd, SOL_SOCKET, SO_REUSEPORT_LB, &on, sizeof(on)) < 0)
+    {
+      msg_error("The kernel refused our SO_REUSEPORT_LB setting",
+                evt_tag_error("error"));
+      return FALSE;
+    }
+  return TRUE;
+#elif defined(SO_REUSEPORT)
   gint on = 1;
   if (setsockopt(fd, SOL_SOCKET, SO_REUSEPORT, &on, sizeof(on)) < 0)
     {
