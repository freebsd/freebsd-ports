--- ./rssdler.py.orig	2010-10-10 03:58:44.112133159 +0000
+++ ./rssdler.py	2010-10-10 03:59:10.937002223 +0000
@@ -2180,6 +2180,7 @@
         elif param == "--purge-saved": _action = 'purge-saved'
         elif param == "--comment-config": _action = 'comment-config'
     signal.signal(signal.SIGINT, signalHandler)
+    signal.signal(signal.SIGTERM, signalHandler)
     sys.excepthook = setDebug #this is NOT supposed to be called!
     if _action == 'comment-config':
         print(commentConfig)
