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
