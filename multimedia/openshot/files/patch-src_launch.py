--- src/launch.py.orig	2026-08-27 04:54:17 UTC
+++ src/launch.py
@@ -83,7 +83,10 @@ if scale != 1.0:
 if scale != 1.0:
     os.environ["QT_SCALE_FACTOR"] = str(scale)
 
-from qt_api import QtCore, QtWidgets
+try:
+    from qt_api import QtCore, QtWidgets
+except ImportError:
+    from .qt_api import QtCore, QtWidgets
 
 Qt = QtCore.Qt
 QApplication = QtWidgets.QApplication
