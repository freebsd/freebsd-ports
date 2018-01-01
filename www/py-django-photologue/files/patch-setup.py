--- setup.py.orig	2016-01-13 21:28:26 UTC
+++ setup.py
@@ -14,7 +14,7 @@ def get_requirements(source):
     except TypeError:
         # Older version of pip.
         install_reqs = parse_requirements(source)
-    required = set([str(ir.req) for ir in install_reqs])
+    required = list([str(ir.req) for ir in install_reqs])
 
     # Temp situation: transition from PIL to Pillow, add a hook so people can
     # skip installing Pillow.
