--- build/pgo/profileserver.py.orig	2011-02-24 21:49:47.000000000 +0100
+++ build/pgo/profileserver.py	2011-02-24 21:50:30.000000000 +0100
@@ -43,13 +43,13 @@ if __name__ == '__main__':
   t.setDaemon(True) # don't hang on exit
   t.start()
   
-  automation.setServerInfo("localhost", PORT)
+  automation.setServerInfo("127.0.0.1", PORT)
   automation.initializeProfile(PROFILE_DIRECTORY)
   browserEnv = automation.environment()
   browserEnv["XPCOM_DEBUG_BREAK"] = "warn"
   browserEnv["MOZ_JAR_LOG_FILE"] = MOZ_JAR_LOG_FILE
 
-  url = "http://localhost:%d/index.html" % PORT
+  url = "http://127.0.0.1:%d/index.html" % PORT
   appPath = os.path.join(SCRIPT_DIR, automation.DEFAULT_APP)
   status = automation.runApp(url, browserEnv, appPath, PROFILE_DIRECTORY, {},
                              debuggerInfo=debuggerInfo,
