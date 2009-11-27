--- examples/designer/plugins/plugins.py.orig	Thu Aug  9 23:42:04 2007
+++ examples/designer/plugins/plugins.py	Thu Aug  9 23:47:13 2007
@@ -11,6 +11,10 @@
 
 from PyQt4 import QtCore, QtGui
 
+# FreeBSD check
+freebsd = False
+if sys.platform[:-1] == 'freebsd': freebsd = True
+
 
 app = QtGui.QApplication(sys.argv)
 
@@ -43,6 +47,8 @@
 
 if sys.platform == 'darwin':
     designer_bin += '/Designer.app/Contents/MacOS/Designer'
+elif freebsd:
+    designer_bin.append("/designer-qt4")
 else:
     designer_bin += '/designer'
 
