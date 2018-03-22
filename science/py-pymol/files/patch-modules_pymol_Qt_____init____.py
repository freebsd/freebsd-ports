--- modules/pymol/Qt/__init__.py.orig	2018-03-22 05:10:42 UTC
+++ modules/pymol/Qt/__init__.py
@@ -28,7 +28,7 @@ if not PYQT_NAME:
         if DEBUG:
             print('import PyQt5 failed')
 
-if not PYQT_NAME:
+if False:
     try:
         __import__("sip").setapi("QString", 2)
         from PyQt4 import QtGui, QtCore, QtOpenGL
@@ -37,7 +37,7 @@ if not PYQT_NAME:
         if DEBUG:
             print('import PyQt4 failed')
 
-if not PYQT_NAME:
+if False:
     try:
         from PySide import QtGui, QtCore, QtOpenGL
         PYQT_NAME = 'PySide'
