--- third_party/dawn/tools/generate-sources-gn.py.orig	2026-08-13 16:48:13 UTC
+++ third_party/dawn/tools/generate-sources-gn.py
@@ -40,8 +40,7 @@ from tools.python import cipd_deps
 
 
 def main() -> int:
-    go_binary = os.path.join(DAWN_ROOT, 'tools', 'golang',
-                             cipd_deps.get_cipd_platform(), 'bin', 'go')
+    go_binary = "go"
     if sys.platform == 'win32':
         go_binary += '.exe'
 
