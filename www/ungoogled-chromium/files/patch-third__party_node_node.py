--- third_party/node/node.py.orig	2022-10-01 07:40:07 UTC
+++ third_party/node/node.py
@@ -16,6 +16,8 @@ def GetBinaryPath():
   return os_path.join(os_path.dirname(__file__), *{
     'Darwin': ('mac', darwin_name, 'bin', 'node'),
     'Linux': ('linux', 'node-linux-x64', 'bin', 'node'),
+    'OpenBSD': ('openbsd', 'node-openbsd', 'bin', 'node'),
+    'FreeBSD': ('freebsd', 'node-freebsd', 'bin', 'node'),
     'Windows': ('win', 'node.exe'),
   }[platform.system()])
 
