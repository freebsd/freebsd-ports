--- deluge/ui/web/web.py.orig	2010-02-17 03:40:21.000000000 -0200
+++ deluge/ui/web/web.py	2010-02-17 03:40:33.000000000 -0200
@@ -33,6 +33,14 @@
 #
 #
 
+try:
+    import psyco
+    import re
+    psyco.cannotcompile(re.compile)
+    psyco.profile()
+except ImportError:
+    pass
+
 import os
 
 from deluge.ui.ui import _UI, UI
