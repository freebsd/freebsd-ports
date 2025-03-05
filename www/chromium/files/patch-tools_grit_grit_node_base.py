--- tools/grit/grit/node/base.py.orig	2025-03-05 08:14:56 UTC
+++ tools/grit/grit/node/base.py
@@ -499,7 +499,8 @@ class Node:
         value = defs
 
       elif name == 'is_linux':
-        value = target_platform == 'linux'
+        value = (target_platform == 'linux'
+                 or 'bsd' in target_platform)
       elif name == 'is_chromeos':
         value = target_platform == 'chromeos'
       elif name == 'is_macosx':
