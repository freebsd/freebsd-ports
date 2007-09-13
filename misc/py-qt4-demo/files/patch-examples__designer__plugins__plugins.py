--- examples/designer/plugins/plugins.py.orig	Thu Aug  9 23:42:04 2007
+++ examples/designer/plugins/plugins.py	Thu Aug  9 23:47:13 2007
@@ -11,6 +11,10 @@
 
 from PyQt4 import QtCore, QtGui
 
+# FreeBSD check
+freebsd = False
+if sys.platform[:-1] == 'freebsd': freebsd = True
+
 
 # Set a specified environment variable with a directory name.
 def setEnvironment(env, var_name, dir_name):
@@ -56,6 +60,8 @@
 
 if sys.platform == "darwin":
     designer_bin.append("/Designer.app/Contents/MacOS/Designer")
+elif freebsd:
+    designer_bin.append("/designer-qt4")
 else:
     designer_bin.append("/designer")
 
