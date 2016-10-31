This patch fixes upload rate speed problem discussed here:
http://forum.deluge-torrent.org/viewtopic.php?f=7&t=33839

--- deluge/core/core.py.orig	2014-07-09 19:08:22 UTC
+++ deluge/core/core.py
@@ -93,7 +93,7 @@
         self.__load_session_state()
 
         # Set the user agent
-        self.settings = lt.session_settings()
+        self.settings = lt.high_performance_seed()
         self.settings.user_agent = "Deluge %s" % deluge.common.get_version()
         # Increase the alert queue size so that alerts don't get lost
         self.settings.alert_queue_size = 10000
