--- third_party/typescript/typescript.py.orig	2026-10-18 13:29:39 UTC
+++ third_party/typescript/typescript.py
@@ -19,6 +19,8 @@ def GetBinaryPath():
   return os_path.normpath(os_path.join(os_path.dirname(__file__), *{
     'Darwin': (darwin_path, 'src', 'lib', 'tsc'),
     'Linux': ('linux-amd64', 'src', 'lib', 'tsc'),
+    'OpenBSD': ('linux-amd64', 'src', 'lib', 'tsc'),
+    'FreeBSD': ('linux-amd64', 'src', 'lib', 'tsc'),
     'Windows': ('windows-amd64', 'src', 'lib', 'tsc.exe'),
   }[platform.system()]))
 
