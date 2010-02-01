--- deluge/ui/gtkui/signals.py.orig	2009-04-07 05:24:02.000000000 +0900
+++ deluge/ui/gtkui/signals.py	2009-05-28 02:39:16.000000000 +0900
@@ -72,8 +72,6 @@
             self.torrent_queue_changed)
         self.receiver.connect_to_signal("torrent_resume_at_stop_ratio",
             self.torrent_resume_at_stop_ratio)
-        self.receiver.connect_to_signal("new_version_available",
-            self.new_version_available)
         self.receiver.connect_to_signal("args_from_external",
             self.args_from_external)
         self.receiver.connect_to_signal("torrent_state_changed",
@@ -152,12 +150,6 @@
         component.get("StatusBar").display_warning(
             text=_("Torrent is past stop ratio."))
 
-    def new_version_available(self, value):
-        log.debug("new_version_available: %s", value)
-        if self.config["show_new_releases"]:
-            from deluge.ui.gtkui.new_release_dialog import NewReleaseDialog
-            NewReleaseDialog().show(value)
-
     def args_from_external(self, value):
         log.debug("args_from_external: %s", value)
         import ipcinterface
