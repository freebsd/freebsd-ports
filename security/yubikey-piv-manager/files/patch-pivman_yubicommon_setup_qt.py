--- pivman/yubicommon/setup/qt.py.orig	2016-08-08 12:58:20 UTC
+++ pivman/yubicommon/setup/qt.py
@@ -32,7 +32,6 @@ from distutils.errors import DistutilsSe
 import os
 
 
-__dependencies__ = ['PySide']
 __yc_dependencies__ = ['ctypes']
 __all__ = ['qt_resources']
 
