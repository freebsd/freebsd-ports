--- spf_engine/policydspfsupp.py.orig	2020-04-18 06:04:36 UTC
+++ spf_engine/policydspfsupp.py
@@ -47,8 +47,8 @@ defaultConfigData = {
         'No_Mail' : False,
         'Mock' : False,
 	# For milter front end
-        'Socket': 'local:/run/pyspf-milter/pyspf-milter.sock',
-        'PidFile': '/run/pyspf-milter/pyspf-milter.pid',
+        'Socket': 'local:/var/run/pyspf-milter/pyspf-milter.sock',
+        'PidFile': '/var/run/pyspf-milter/pyspf-milter.pid',
         'UserID': 'pyspf-milter',
         'UMask': 7,
         'InternalHosts': '127.0.0.1',
@@ -153,9 +153,9 @@ def _readConfigFile(path, configData = None, configGlo
             'Socket': str,
             'PidFile': str,
             'UserID': str,
-            'UMask': 'int',
+            'UMask': int,
             'InternalHosts': str,
-            'IntHosts': 'bool',
+            'IntHosts': bool,
             'MacroListVerify': str,
             }
 
