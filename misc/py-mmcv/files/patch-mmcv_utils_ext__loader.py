-- Use importlib.util.find_spec() instead of pkgutil.find_loader(), removed in Python 3.14.
-- upstreamed: https://github.com/open-mmlab/mmcv/pull/3347

--- mmcv/utils/ext_loader.py.orig	2024-04-24 14:24:15 UTC
+++ mmcv/utils/ext_loader.py
@@ -1,7 +1,7 @@ import importlib
 # Copyright (c) OpenMMLab. All rights reserved.
 import importlib
+import importlib.util
 import os
-import pkgutil
 import warnings
 from collections import namedtuple
 
@@ -68,5 +68,5 @@ def check_ops_exist() -> bool:
 
 
 def check_ops_exist() -> bool:
-    ext_loader = pkgutil.find_loader('mmcv._ext')
+    ext_loader = getattr(importlib.util.find_spec('mmcv._ext'), 'loader', None)
     return ext_loader is not None
