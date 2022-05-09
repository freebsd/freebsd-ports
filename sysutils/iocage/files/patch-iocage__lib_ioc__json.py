--- iocage_lib/ioc_json.py.orig	2022-05-09 15:10:29 UTC
+++ iocage_lib/ioc_json.py
@@ -543,7 +543,7 @@ class IOCZFS(object):
                 'zfs',
                 'get',
                 '-pHo',
-                'property, value',
+                'property,value',
                 'all',
                 identifier
             ], stdout=su.PIPE, stderr=su.PIPE
