--- setup.py.orig	2018-01-16 17:43:41 UTC
+++ setup.py
@@ -38,8 +38,6 @@ def _data_files():
         files = glob.glob(os.path.join('share', 'icons', theme, '*.svg'))
         yield directory, files
 
-    yield os.path.join('share', 'doc', 'scudcloud'), \
-        ['LICENSE', 'README']
     yield os.path.join('share', 'applications'), \
         glob.glob(os.path.join('share', '*.desktop'))
     yield os.path.join('share', 'pixmaps'), \
@@ -59,8 +57,7 @@ setup(name='scudcloud',
       maintainer='Andrew Stiegmann',
       maintainer_email='andrew.stiegmann@gmail.com',
       package_data = {
-          # *.js will be processed separately
-          'scudcloud': ['resources/*.css', 'resources/*.html', 'resources/*.png',]
+          'scudcloud': ['resources/*.css', 'resources/*.html', 'resources/*.png', 'resources/*.js']
       },
       packages=['scudcloud',],
       requires=['dbus', 'PyQt5',],
