--- napalm_logs/config/__init__.py.orig	2018-05-19 10:13:50 UTC
+++ napalm_logs/config/__init__.py
@@ -11,7 +11,8 @@ import napalm_logs.ext.six as six
 
 # config
 ROOT_DIR = '/'
-CONFIG_FILE = os.path.join(ROOT_DIR, 'etc', 'napalm', 'logs')
+#CONFIG_FILE = os.path.join(ROOT_DIR, 'etc', 'napalm', 'logs')
+CONFIG_FILE = os.path.join('%%PREFIX%%', 'etc', 'napalm', 'logs')
 ADDRESS = '0.0.0.0'
 PORT = 514
 LISTENER = 'udp'
