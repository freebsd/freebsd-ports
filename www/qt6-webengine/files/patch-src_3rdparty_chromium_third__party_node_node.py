--- src/3rdparty/chromium/third_party/node/node.py.orig	2025-08-15 18:30:00 UTC
+++ src/3rdparty/chromium/third_party/node/node.py
@@ -40,6 +40,8 @@ def GetBinaryPath():
   return os_path.join(os_path.dirname(__file__), *{
     'Darwin': (darwin_path, darwin_name, 'bin', 'node'),
     'Linux': ('linux', 'node-linux-x64', 'bin', 'node'),
+    'OpenBSD': ('openbsd', 'node-openbsd', 'bin', 'node'),
+    'FreeBSD': ('freebsd', 'node-freebsd', 'bin', 'node'),
     'Windows': ('win', 'node.exe'),
   }[platform.system()])
 
