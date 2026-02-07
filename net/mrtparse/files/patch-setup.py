--- setup.py.orig	2019-01-08 09:46:20 UTC
+++ setup.py
@@ -29,6 +29,7 @@ except ImportError:
 import os
 import sys
 from codecs import open
+from glob import glob
 import mrtparse
 
 here = os.path.abspath(os.path.dirname(__file__))
@@ -67,14 +68,7 @@ try:
         ],
         keywords='mrt bgp',
         packages = ['mrtparse'],
-        package_data={
-            'mrtparse': [
-                'examples/*.py',
-                'samples/bird*',
-                'samples/openbgpd*',
-                'samples/quagga*'
-            ]
-        },
+        scripts=glob('examples/*'),
         zip_safe=False,
     )
 finally:
