--- ./BitTorrent/Torrent.py.orig	Wed Jul 12 02:18:28 2006
+++ ./BitTorrent/Torrent.py	Sat Jul 29 00:08:59 2006
@@ -58,7 +58,6 @@
 
 from khashmir import const
 
-
 class Feedback(object):
     """Inidivual torrents (Torrent) perform callbacks regarding
        changes of state to the rest of the program via a Feedback
@@ -90,8 +89,9 @@
     POLICIES = ["stop", "start", "auto"]
     PRIORITIES = ["low", "normal", "high"]
 
-    def __init__(self, metainfo, working_path, destination_path, config,
-                 data_dir, rawserver, choker,
+    def __init__(self, metainfo, working_path, destination_path,
+                 saveas_style_working_path, saveas_style_destination_path,
+                 config, data_dir, rawserver, choker,
                  singleport_listener, ratelimiter, total_downmeasure,
                  filepool, dht, feedback, log_root,
                  hidden=False, is_auto_update=False):
@@ -152,8 +152,11 @@
 
         self.config = Preferences(config)#, persist_callback=self._dump_torrent_config)
         self.working_path = working_path #sets in config. See _set_working_path
-
         self.destination_path = destination_path # sets in config.
+
+        self.saveas_style_working_path = saveas_style_working_path
+        self.saveas_style_destination_path = saveas_style_destination_path
+
         self.priority = "normal"
         self.policy = "auto"
 
@@ -258,6 +261,9 @@
     def is_running(self):
         return self.state == "running"
 
+    def is_seeding(self):
+        return self._activity == (_("seeding"), 1)
+
     def is_context_valid(self):
         return self.context_valid
 
@@ -819,8 +825,13 @@
             self.logger.debug("successfully paused torrent, moving file")
 
             self.state = "finishing"
-            df = ThreadedDeferred(_wrap_task(self._rawserver.external_add_task),
-                                  move, self.working_path, self.destination_path)
+            if self.saveas_style_working_path is not None and self.saveas_style_destination_path is not None:
+                df = ThreadedDeferred(_wrap_task(self._rawserver.external_add_task),
+                                      move, self.saveas_style_working_path,
+                                      self.saveas_style_destination_path)
+            else:
+                df = ThreadedDeferred(_wrap_task(self._rawserver.external_add_task),
+                                      move, self.working_path, self.destination_path)
             yield df
             df.getResult()
 
