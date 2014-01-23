--- setup.py.orig	2013-10-28 18:04:02.000000000 +0200
+++ setup.py	2014-01-22 21:29:49.000000000 +0200
@@ -15,7 +15,7 @@
 library_dirs = []
 include_dirs = []
 extra_objects = []
-extra_compile_args=['-ggdb', '-O0']
+extra_compile_args=['-fPIC']
 
 ext_files = ['ffmpeg/_ffmpeg.pyx']
 root_ffmpeg = environ.get('FFMPEG_ROOT')
@@ -29,14 +29,13 @@
     if environ.get('FFMPEG_LIBRARY_DIRS'):
         library_dirs += environ.get('FFMPEG_LIBRARY_DIRS').split(' ')
     libraries = environ.get('FFMPEG_LIBRARIES', 'gcc z sdl sdl_mixer m').split(' ')
-    extra_compile_args = ['-ggdb', '-O0']
     p = join(root_ffmpeg, 'lib')
-    extra_objects = [
-        join(p, 'libavformat.a'),
-        join(p, 'libavcodec.a'),
-        join(p, 'libswscale.a'),
-        join(p, 'libavresample.a'),
-        join(p, 'libavutil.a')]
+    libraries += [
+        'avformat',
+        'avcodec',
+        'swscale',
+        'avresample',
+        'avutil']
 
 elif not have_cython:
     # Special hack for PGS4A-android, should we deprecated it ?
