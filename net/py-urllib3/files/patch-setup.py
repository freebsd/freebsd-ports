--- setup.py.orig	2016-09-06 14:39:59 UTC
+++ setup.py
@@ -61,7 +61,7 @@ setup(name='urllib3',
               'certifi',
           ],
           'socks': [
-              'PySocks>=1.5.6,<2.0,!=1.5.7',
+              'PySocks>=1.5.6',
           ]
       },
       )
