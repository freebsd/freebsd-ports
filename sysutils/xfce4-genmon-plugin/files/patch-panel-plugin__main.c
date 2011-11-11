--- ./panel-plugin/main.c.orig	2011-11-11 18:35:50.000000000 +0100
+++ ./panel-plugin/main.c	2011-11-11 18:36:46.000000000 +0100
@@ -836,6 +836,8 @@
 
     SetMonitorFont (genmon);
 
+    SetTimer (genmon);
+
     g_signal_connect (plugin, "free-data", G_CALLBACK (genmon_free), genmon);
 
     g_signal_connect (plugin, "save", G_CALLBACK (genmon_write_config),
