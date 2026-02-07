--- src/classes/logger_libopenshot.py.orig	2024-06-24 20:49:58 UTC
+++ src/classes/logger_libopenshot.py
@@ -59,7 +59,7 @@ class LoggerLibOpenShot(Thread):
         debug_enabled = s.get("debug-mode")
 
         # Set port on ZmqLogger singleton
-        openshot.ZmqLogger.Instance().Connection("tcp://*:%s" % port)
+        openshot.ZmqLogger.Instance().Connection("tcp://localhost:%s" % port)
 
         # Set filepath for ZmqLogger also
         openshot.ZmqLogger.Instance().Path(os.path.join(info.USER_PATH, 'libopenshot.log'))
