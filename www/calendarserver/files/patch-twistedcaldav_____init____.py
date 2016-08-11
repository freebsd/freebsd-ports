--- twistedcaldav/__init__.py.orig	2016-01-07 15:18:44 UTC
+++ twistedcaldav/__init__.py
@@ -33,6 +33,10 @@ File.contentTypes = loadMimeTypes(("/etc
 # Register additional WebDAV XML elements
 #
 
+# Make sure the default config is loaded and updated early on to avoid race conditions during startup. (upstream: r15635)
+from twistedcaldav.config import config 
+config.update()
+
 import twistedcaldav.caldavxml
 import twistedcaldav.carddavxml
 import twistedcaldav.mkcolxml
