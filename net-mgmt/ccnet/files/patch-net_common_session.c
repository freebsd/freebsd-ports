--- net/common/session.c.orig	2014-09-03 04:04:21.072122386 -0400
+++ net/common/session.c	2014-09-03 04:04:58.071390609 -0400
@@ -168,6 +168,7 @@
     g_free (name);
     g_free (user_name);
     g_free (port_str);
+    g_free (lport_str);
 #ifdef CCNET_SERVER
     g_free (service_url);
 #endif
