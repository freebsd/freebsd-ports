--- third_party/devtools-frontend/src/third_party/typescript/typescript.py.orig	2026-10-31 12:09:36 UTC
+++ third_party/devtools-frontend/src/third_party/typescript/typescript.py
@@ -10,6 +10,9 @@ import os
 
 
 def GetBinaryPath():
+    if platform.system() in ['OpenBSD', 'FreeBSD']:
+        return "tsc"
+
     if platform.machine() == 'arm64':
         darwin_path = 'mac-arm64'
     else:
