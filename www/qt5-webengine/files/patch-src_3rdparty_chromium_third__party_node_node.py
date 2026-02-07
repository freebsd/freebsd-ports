--- src/3rdparty/chromium/third_party/node/node.py.orig	2019-05-23 12:39:34 UTC
+++ src/3rdparty/chromium/third_party/node/node.py
@@ -12,6 +12,7 @@ import sys
 def GetBinaryPath():
   return os_path.join(os_path.dirname(__file__), *{
     'Darwin': ('mac', 'node-darwin-x64', 'bin', 'node'),
+    'FreeBSD': ('freebsd', 'node-freebsd-x64', 'bin', 'node'),
     'Linux': ('linux', 'node-linux-x64', 'bin', 'node'),
     'Windows': ('win', 'node.exe'),
   }[platform.system()])
