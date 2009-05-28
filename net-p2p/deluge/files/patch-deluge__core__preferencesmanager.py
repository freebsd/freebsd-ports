--- deluge/core/preferencesmanager.py.orig	2009-05-16 03:09:59.000000000 +0900
+++ deluge/core/preferencesmanager.py	2009-05-28 02:24:21.000000000 +0900
@@ -105,7 +105,6 @@
     "auto_managed": True,
     "move_completed": False,
     "move_completed_path": deluge.common.get_default_download_dir(),
-    "new_release_check": True,
     "proxies": {
         "peer": {
             "type": 0,
@@ -215,9 +214,6 @@
             self._on_send_info)
         self.config.register_set_function("proxies",
             self._on_set_proxies)
-        self.new_release_timer = None
-        self.config.register_set_function("new_release_check",
-            self._on_new_release_check)
         self.config.register_set_function("rate_limit_ip_overhead",
             self._on_rate_limit_ip_overhead)
 
@@ -457,19 +453,6 @@
         if value:
             Send_Info_Thread(self.config).start()
 
-    def _on_new_release_check(self, key, value):
-        if value:
-            log.debug("Checking for new release..")
-            threading.Thread(target=self.core.get_new_release).start()
-            if self.new_release_timer:
-                gobject.source_remove(self.new_release_timer)
-            # Set a timer to check for a new release every 3 days
-            self.new_release_timer = gobject.timeout_add(
-                72 * 60 * 60 * 1000, self._on_new_release_check, "new_release_check", True)
-        else:
-            if self.new_release_timer:
-                gobject.source_remove(self.new_release_timer)
-
     def _on_set_proxies(self, key, value):
         for k, v in value.items():
             if v["type"]:
