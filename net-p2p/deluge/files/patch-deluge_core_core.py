--- deluge/core/core.py.orig	2009-05-16 03:09:59.000000000 +0900
+++ deluge/core/core.py	2009-05-28 02:42:12.000000000 +0900
@@ -232,9 +227,6 @@
         # Start the AuthManager
         self.authmanager = AuthManager()
 
-        # New release check information
-        self.new_release = None
-
         component.start("PreferencesManager")
         component.start()
 
@@ -319,54 +311,6 @@
         except Exception, e:
             log.warning("Failed to save dht state: %s", e)
 
-    def get_new_release(self):
-        log.debug("get_new_release")
-        from urllib2 import urlopen
-        try:
-            self.new_release = urlopen(
-                "http://download.deluge-torrent.org/version-1.0").read().strip()
-        except Exception, e:
-            log.debug("Unable to get release info from website: %s", e)
-            return
-        self.check_new_release()
-
-    def check_new_release(self):
-        if self.new_release:
-            log.debug("new_release: %s", self.new_release)
-            class VersionSplit(object):
-                def __init__(self, ver):
-                    ver = ver.lower()
-                    vs = ver.split("_") if "_" in ver else ver.split("-")
-                    self.version = vs[0]
-                    self.suffix = None
-                    if len(vs) > 1:
-                        for s in ("rc", "alpha", "beta", "dev"):
-                            if s in vs[1][:len(s)]:
-                                self.suffix = vs[1]
-
-                def __cmp__(self, ver):
-                    if self.version > ver.version or (self.suffix and self.suffix[:3] == "dev"):
-                        return 1
-                    if self.version < ver.version:
-                        return -1
-
-                    if self.version == ver.version:
-                        if self.suffix == ver.suffix:
-                            return 0
-                        if self.suffix is None:
-                            return 1
-                        if ver.suffix is None:
-                            return -1
-                        if self.suffix < ver.suffix:
-                            return -1
-                        if self.suffix > ver.suffix:
-                            return 1
-
-            if VersionSplit(self.new_release) > VersionSplit(deluge.common.get_version()):
-                self.signals.emit("new_version_available", self.new_release)
-                return self.new_release
-        return False
-
     # Exported Methods
     def export_ping(self):
         """A method to see if the core is running"""
@@ -381,8 +325,6 @@
         """Registers a client with the signal manager so that signals are
             sent to it."""
         self.signals.register_client(self.client_address, port)
-        if self.config["new_release_check"]:
-            self.check_new_release()
 
     def export_deregister_client(self):
         """De-registers a client with the signal manager."""
