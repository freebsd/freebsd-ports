--- setup.py.orig	2018-12-20 12:20:35 UTC
+++ setup.py
@@ -48,7 +48,7 @@ protocols and transports.
 
 try:
     os.stat('CHANGELOG.rst')
-    LONG_DESC += u"\n\n" + open('CHANGELOG.rst', 'r').read().decode('utf8')
+    LONG_DESC += u"\n\n" + open('CHANGELOG.rst', 'rb').read().decode('utf8')
 except OSError:
     pass
 
