--- agent.py.orig	2014-10-24 11:01:07 UTC
+++ agent.py
@@ -64,10 +64,10 @@
 
     config = ConfigParser.ConfigParser()
 
-    if os.path.exists('/etc/sd-agent/conf.d/'):
-        configPath = '/etc/sd-agent/conf.d/'
-    elif os.path.exists('/etc/sd-agent/config.cfg'):
-        configPath = '/etc/sd-agent/config.cfg'
+    if os.path.exists('%%PREFIX%%/etc/sd-agent/conf.d/'):
+        configPath = '%%PREFIX%%/etc/sd-agent/conf.d/'
+    elif os.path.exists('%%PREFIX%%/etc/sd-agent/config.cfg'):
+        configPath = '%%PREFIX%%/etc/sd-agent/config.cfg'
     else:
         configPath = path + '/config.cfg'
 
