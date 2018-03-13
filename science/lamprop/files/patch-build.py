--- build.py.orig	2018-03-13 08:20:32 UTC
+++ build.py
@@ -28,7 +28,7 @@ def mkarchive(name, modules, main='__mai
     """
     std = '__main__.py'
     vi = sys.version_info
-    shebang = '#!/usr/bin/env python{}\n'.format(vi.major).encode('ascii')
+    shebang = '#!/usr/bin/env python{}.{}\n'.format(vi.major, vi.minor).encode('ascii')
     if isinstance(modules, str):
         modules = [modules]
     if main != std:
