--- plugin_install.py.orig	2016-02-08 09:48:27 UTC
+++ plugin_install.py
@@ -50,10 +50,8 @@ def startGUIInstall():
 
 def installPlugin():
     exec_str = sys.executable
-    passwordObj = password.Password(mode)
     cmd = "%s installPlugin.py"%exec_str
-    cmd = passwordObj.getAuthCmd()%cmd
-    status, output = utils.run(cmd, passwordObj)
+    status, output = utils.run(cmd)
     if status == 0:
         result = True
     else:
