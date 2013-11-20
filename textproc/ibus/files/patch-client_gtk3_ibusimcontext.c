--- client/gtk3/ibusimcontext.c.orig	2013-04-17 01:31:01.000000000 +0000
+++ client/gtk3/ibusimcontext.c	2013-06-17 07:23:44.000000000 +0000
@@ -563,10 +563,10 @@
 
     /* always install snooper */
     if (_key_snooper_id == 0) {
-#pragma GCC diagnostic push
-#pragma GCC diagnostic ignored "-Wdeprecated-declarations"
+//#pragma GCC diagnostic push
+//#pragma GCC diagnostic ignored "-Wdeprecated-declarations"
         _key_snooper_id = gtk_key_snooper_install (_key_snooper_cb, NULL);
-#pragma GCC diagnostic pop
+//#pragma GCC diagnostic pop
     }
 
     _daemon_name_watch_id = g_bus_watch_name (G_BUS_TYPE_SESSION,
@@ -583,10 +583,10 @@
 {
     if (_key_snooper_id != 0) {
         IDEBUG ("snooper is terminated.");
-#pragma GCC diagnostic push
-#pragma GCC diagnostic ignored "-Wdeprecated-declarations"
+//#pragma GCC diagnostic push
+//#pragma GCC diagnostic ignored "-Wdeprecated-declarations"
         gtk_key_snooper_remove (_key_snooper_id);
-#pragma GCC diagnostic pop
+//#pragma GCC diagnostic pop
         _key_snooper_id = 0;
     }
 
