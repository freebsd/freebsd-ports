--- ./setup.py.orig	2012-09-12 11:20:03.000000000 +0400
+++ ./setup.py	2012-09-16 15:47:34.000000000 +0400
@@ -8,7 +8,7 @@
 description = 'National characters transcription module.'
 
 import trans
-long_description = open('README.rst', 'rb').read()
+#long_description = open('README.rst', 'rb').read()
 version = trans.__version__
 
 
@@ -16,7 +16,7 @@
         name='trans',
         version=version,
         description=description,
-        long_description=long_description,
+        long_description=description,
         author='Zelenyak Aleksandr aka ZZZ',
         author_email='ZZZ.Sochi@GMail.com',
         url='https://github.com/zzzsochi/trans',
