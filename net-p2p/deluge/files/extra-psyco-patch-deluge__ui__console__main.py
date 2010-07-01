--- deluge/ui/console/main.py.orig	2010-02-17 03:37:21.000000000 -0200
+++ deluge/ui/console/main.py	2010-02-17 03:38:06.000000000 -0200
@@ -34,6 +34,14 @@
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
 import os, sys
 import optparse
 import shlex
