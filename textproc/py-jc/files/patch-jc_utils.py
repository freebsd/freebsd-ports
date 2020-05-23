Platform check fails as sys.platform returns 'freebsd' plus
the release version e.g., 'freebsd12' and so forth where the string
'freebsd' is only listed as compatible.

--- jc/utils.py.orig	2020-05-23 14:53:34 UTC
+++ jc/utils.py
@@ -1,8 +1,8 @@
 """jc - JSON CLI output utility utils"""
 import textwrap
 import sys
+import re
 
-
 def warning_message(message):
     """
     Prints a warning message for non-fatal issues
@@ -56,7 +56,8 @@ def compatibility(mod_name, compatible):
 
         no return, just prints output to STDERR
     """
-    if sys.platform not in compatible:
+    platform = re.sub(r'\d+', '', sys.platform)
+    if platform not in compatible:
         mod = mod_name.split('.')[-1]
         compat_list = ', '.join(compatible)
         warning_message(f'{mod} parser not compatible with your OS ({sys.platform}).\n         Compatible platforms: {compat_list}')
