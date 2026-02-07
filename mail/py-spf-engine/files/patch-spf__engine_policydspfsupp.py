--- spf_engine/policydspfsupp.py.orig	2022-12-17 04:55:15 UTC
+++ spf_engine/policydspfsupp.py
@@ -49,8 +49,8 @@ defaultConfigData = {
         'Mock' : False,
         'Queue_ID' : True,
 	# For milter front end
-        'Socket': 'local:/run/pyspf-milter/pyspf-milter.sock',
-        'PidFile': '/run/pyspf-milter/pyspf-milter.pid',
+        'Socket': 'local:/var/run/pyspf-milter/pyspf-milter.sock',
+        'PidFile': '/var/run/pyspf-milter/pyspf-milter.pid',
         'UserID': 'pyspf-milter',
         'UMask': 7,
         'InternalHosts': ['127.0.0.1'],
