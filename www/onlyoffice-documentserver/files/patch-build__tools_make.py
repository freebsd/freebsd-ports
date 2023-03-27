--- build_tools/make.py.orig	2023-03-27 10:50:23 UTC
+++ build_tools/make.py
@@ -8,7 +8,7 @@ import base
 sys.path.append('scripts/core_common/modules')
 import config
 import base
-import build
+from scripts import build
 import build_js
 import build_server
 import deploy
