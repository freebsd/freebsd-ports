--- tools/install.py.orig	2012-09-18 08:54:59.000000000 +0800
+++ tools/install.py	2012-09-18 12:17:19.000000000 +0800
@@ -114,7 +114,7 @@
     assert(0) # unhandled action type
 
 def files(action):
-  action(['doc/node.1'], 'share/man/man1/')
+  action(['doc/node.1'], 'man/man1/')
   action(['out/Release/node'], 'bin/node')
 
   # install unconditionally, checking if the platform supports dtrace doesn't
