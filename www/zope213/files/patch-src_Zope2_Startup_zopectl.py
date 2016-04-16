Make Zope2 work with zdaemon greater than 3.x
https://bugs.launchpad.net/zope2/+bug/1386795

--- src/Zope2/Startup/zopectl.py.orig	2016-02-29 16:37:07 UTC
+++ src/Zope2/Startup/zopectl.py
@@ -151,6 +151,8 @@ class ZopeCtlOptions(ZDOptions):
                  default=1)
         self.add("start_timeout", "runner.start_timeout",
                  "T:", "start-timeout=", int, default=300)
+        self.add("transcript", "runner.transcript", "t:", "transcript=",
+                 default="/dev/null") 
         self.add("logfile", None, "l:", "logfile=")
         self.add("user", "runner.user", "u:", "user=")
         self.add("prompt", "runner.prompt", default="zopectl>")
