--- third_party/typescript/typescript.py.orig	2026-09-25 15:26:43 UTC
+++ third_party/typescript/typescript.py
@@ -11,6 +11,9 @@ import os
 
 
 def GetBinaryPath():
+  if platform.system() in ['OpenBSD', 'FreeBSD']:
+    return "tsc"
+
   if platform.machine() == 'arm64':
     darwin_path = 'mac-arm64'
   else:
