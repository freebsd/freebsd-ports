Obtained from:  https://github.com/arskom/spyne/commit/4b89a21f9af72f07628d2ecd114c308987acc0e1

--- setup.py.orig	2016-10-28 11:15:20 UTC
+++ setup.py
@@ -48,7 +48,7 @@ protocols and transports.
 
 try:
     os.stat('CHANGELOG.rst')
-    LONG_DESC += "\n\n" + open('CHANGELOG.rst', 'r').read()
+    LONG_DESC += u"\n\n" + open('CHANGELOG.rst', 'rb').read().decode('utf8')
 except OSError:
     pass
 
