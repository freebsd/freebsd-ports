--- setup.py.orig	2014-12-31 15:34:31 UTC
+++ setup.py
@@ -31,12 +31,14 @@ setup(
     install_requires = [
         'setuptools',
         'PyCrypto',
-        'Twisted',
-        'argparse',
+        'Twisted_Core',
         'pyptlib >= 0.0.6',
         'pyyaml'
         ],
 
+    #if sys.version_info < (2, 7):
+    #    install_requires.append('argparse')
+
     extras_require = {
         'SOCKS': ["txsocksx"]
         }
