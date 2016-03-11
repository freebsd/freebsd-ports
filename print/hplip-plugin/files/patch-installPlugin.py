--- installPlugin.py.orig	2016-02-08 09:48:27 UTC
+++ installPlugin.py
@@ -52,7 +52,7 @@ pluginObj = pluginhandler.PluginHandle()
  
 status = False
  
-if os.geteuid() == 0:
+if True:
     status = pluginObj.copyFiles(os.getcwd())
     if status == True:
         sys.exit(0)
