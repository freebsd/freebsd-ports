--- third_party/node/node.py.orig	2020-11-13 06:37:03 UTC
+++ third_party/node/node.py
@@ -13,6 +13,7 @@ import os
 def GetBinaryPath():
   return os_path.join(os_path.dirname(__file__), *{
     'Darwin': ('mac', 'node-darwin-x64', 'bin', 'node'),
+    'FreeBSD': ('freebsd', 'node-freebsd-x64', 'bin', 'node'),
     'Linux': ('linux', 'node-linux-x64', 'bin', 'node'),
     'Windows': ('win', 'node.exe'),
   }[platform.system()])
