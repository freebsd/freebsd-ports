--- twistedcaldav/stdconfig.py.orig	2016-03-01 19:59:08 UTC
+++ twistedcaldav/stdconfig.py
@@ -53,7 +53,7 @@ log = Logger()
 if platform.isMacOSX():
     DEFAULT_CONFIG_FILE = "/Applications/Server.app/Contents/ServerRoot/private/etc/caldavd/caldavd-apple.plist"
 else:
-    DEFAULT_CONFIG_FILE = "/etc/caldavd/caldavd.plist"
+    DEFAULT_CONFIG_FILE = "/usr/local/etc/caldavd/caldavd.plist"
 
 DEFAULT_SERVICE_PARAMS = {
     "xml": {
@@ -1827,6 +1827,8 @@ config.setProvider(PListConfigProvider(D
 config.addPreUpdateHooks(PRE_UPDATE_HOOKS)
 config.addPostUpdateHooks(POST_UPDATE_HOOKS)
 
+# Make sure the default config is loaded and updated early on to avoid race conditions during startup. (upstream: r15635)
+config.update() 
 
 def _preserveConfig(configDict):
     """
