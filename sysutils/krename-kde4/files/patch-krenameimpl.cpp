--- krename/krenameimpl.cpp.orig	Sun Feb 13 20:32:52 2005
+++ krename/krenameimpl.cpp	Sun Feb 13 20:36:36 2005
@@ -96,7 +96,7 @@
     plugin = PluginLoader::instance();
     helpDialogData = new HelpDialogData();
     // Maybe parent instead of 0 but might crash when switching from wizard to tab mode
-    helpDialog = new HelpDialog( helpDialogData, 0, false );
+    helpDialog = new HelpDialog( helpDialogData, 0, 0, false );
 
     m_switching = false;
     
