--- setup.py.orig	2019-06-24 21:32:20 UTC
+++ setup.py
@@ -2,25 +2,15 @@
 import uuid
 import os
 from setuptools import setup, find_packages
-from pip.req import parse_requirements
+from pkg_resources import parse_requirements
 
 import photologue
 
 
 def get_requirements(source):
+    with open(source) as f:
+        return sorted({str(req) for req in parse_requirements(f.read())})
 
-    try:
-        install_reqs = parse_requirements(source, session=uuid.uuid1())
-    except TypeError:
-        # Older version of pip.
-        install_reqs = parse_requirements(source)
-    required = list(set([str(ir.req) for ir in install_reqs]))
-
-    # Temp situation: transition from PIL to Pillow, add a hook so people can
-    # skip installing Pillow.
-    if os.path.exists('/tmp/PHOTOLOGUE_NO_PILLOW'):
-        required = [item for item in required if not item.startswith('Pillow')]
-    return required
 
 setup(
     name="django-photologue",
