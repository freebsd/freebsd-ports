--- deluge/main.py.orig	2010-02-17 00:17:31.000000000 -0200
+++ deluge/main.py	2010-02-17 00:18:56.000000000 -0200
@@ -34,6 +34,13 @@
 
 #
 
+try:
+    import psyco
+    import re
+    psyco.cannotcompile(re.compile)
+    psyco.profile()
+except ImportError:
+    pass
 
 # The main starting point for the program.    This function is called when the
 # user runs the command 'deluge'.
