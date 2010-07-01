--- deluge/ui/gtkui/gtkui.py.orig	2010-02-17 03:39:33.000000000 -0200
+++ deluge/ui/gtkui/gtkui.py	2010-02-17 03:39:45.000000000 -0200
@@ -33,6 +33,13 @@
 #
 #
 
+try:
+    import psyco
+    import re
+    psyco.cannotcompile(re.compile)
+    psyco.profile()
+except ImportError:
+    pass
 
 from deluge.log import LOG as log
 
