--- deluge/main.py.orig	2010-02-17 01:16:05.000000000 -0200
+++ deluge/main.py	2010-02-17 01:16:40.000000000 -0200
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
 
 # The main starting point for the program.    This function is called when the
 # user runs the command 'deluge'.
