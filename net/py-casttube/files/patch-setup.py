--- setup.py.orig	2020-04-08 12:40:53 UTC
+++ setup.py
@@ -12,7 +12,6 @@ setup(name='casttube',
       author='Uri Katz',
       author_email='4urikatz@gmail.com',
       license='MIT',
-      data_files = [("", ["LICENSE"])],
       packages=['casttube'],
       zip_safe=False,
       keywords = ['youtube', 'chromecast', 'youtube-api'],
