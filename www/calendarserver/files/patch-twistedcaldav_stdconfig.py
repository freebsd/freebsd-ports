--- twistedcaldav/stdconfig.py.orig	2016-08-23 16:28:28 UTC
+++ twistedcaldav/stdconfig.py
@@ -53,7 +53,7 @@ log = Logger()
 if platform.isMacOSX():
     DEFAULT_CONFIG_FILE = "/Applications/Server.app/Contents/ServerRoot/private/etc/caldavd/caldavd-apple.plist"
 else:
-    DEFAULT_CONFIG_FILE = "/etc/caldavd/caldavd.plist"
+    DEFAULT_CONFIG_FILE = "/usr/local/etc/caldavd/caldavd.plist"
 
 DEFAULT_SERVICE_PARAMS = {
     "xml": {
