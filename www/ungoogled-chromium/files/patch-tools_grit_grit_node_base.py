--- tools/grit/grit/node/base.py.orig	2026-10-31 12:09:36 UTC
+++ tools/grit/grit/node/base.py
@@ -511,7 +511,8 @@ class Node:
         value = defs
 
       elif name == 'is_linux':
-        value = target_platform == 'linux'
+        value = (target_platform == 'linux'
+                 or 'bsd' in target_platform)
       elif name == 'is_chromeos':
         value = target_platform == 'chromeos'
       elif name == 'is_macosx':
