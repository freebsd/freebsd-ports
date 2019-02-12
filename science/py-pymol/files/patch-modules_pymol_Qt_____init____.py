--- modules/pymol/Qt/__init__.py.orig	2019-02-11 14:08:10 UTC
+++ modules/pymol/Qt/__init__.py
@@ -29,7 +29,7 @@ if not PYQT_NAME:
         if DEBUG:
             print('import PyQt5 failed')
 
-if not PYQT_NAME:
+if False:
     try:
         from PySide2 import QtGui, QtCore, QtOpenGL, QtWidgets
         PYQT_NAME = 'PySide2'
@@ -46,7 +46,7 @@ if not PYQT_NAME:
         if DEBUG:
             print('import PyQt4 failed')
 
-if not PYQT_NAME:
+if False:
     try:
         from PySide import QtGui, QtCore, QtOpenGL
         PYQT_NAME = 'PySide'
