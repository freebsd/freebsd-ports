--- setup.py.orig	2022-09-28 03:22:02 UTC
+++ setup.py
@@ -104,6 +104,7 @@ class OTIO_build_ext(setuptools.command.build_ext.buil
             '-DBUILD_TESTING:BOOL=OFF',
             # Python modules wil be installed by setuptools.
             '-DOTIO_INSTALL_PYTHON_MODULES:BOOL=OFF',
+            '-DOTIO_FIND_IMATH:BOOL=ON',
         ]
         if self.is_windows():
             if self.is_mingw():
