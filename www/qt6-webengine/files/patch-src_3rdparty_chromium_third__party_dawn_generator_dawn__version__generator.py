--- src/3rdparty/chromium/third_party/dawn/generator/dawn_version_generator.py.orig	2022-09-26 10:05:50 UTC
+++ src/3rdparty/chromium/third_party/dawn/generator/dawn_version_generator.py
@@ -27,11 +27,14 @@ def get_gitHash(dawnDir):
 
 
 def get_gitHash(dawnDir):
-    result = subprocess.run([get_git(), 'rev-parse', 'HEAD'],
-                            stdout=subprocess.PIPE,
-                            cwd=dawnDir)
-    if result.returncode == 0:
-        return result.stdout.decode('utf-8').strip()
+    try:
+        result = subprocess.run([get_git(), "rev-parse", "HEAD"],
+                                stdout=subprocess.PIPE,
+                                cwd=dawnDir)
+        if result.returncode == 0:
+            return result.stdout.decode("utf-8").strip()
+    except Exception:
+        return ""
     # No hash was available (possibly) because the directory was not a git checkout. Dawn should
     # explicitly handle its absenece and disable features relying on the hash, i.e. caching.
     return ''
