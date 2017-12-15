--- calendarserver/tools/dkimtool.py.orig	2017-08-28 15:45:35.281722000 -0400
+++ calendarserver/tools/dkimtool.py	2017-08-28 15:47:12.632627000 -0400
@@ -36,7 +36,7 @@
 
 def _doKeyGeneration(options):
 
-    key = RSA.generate(options["key-size"])
+    key = RSA.generate(int(options["key-size"]))
     output = key.exportKey()
     lineBreak = False
     if options["key"]:
@@ -289,12 +289,6 @@
     options = DKIMToolOptions()
     options.parseOptions(argv[1:])
 
-    #
-    # Send logging output to stdout
-    #
-    observer = STDLibLogObserver()
-    observer.start()
-
     if options["verbose"]:
         log.levels().setLogLevelForNamespace("txdav.caldav.datastore.scheduling.ischedule.dkim", LogLevel.debug)
 
