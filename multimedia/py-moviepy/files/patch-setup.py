Obtained from:	https://github.com/Zulko/moviepy/commit/2947e4a036513a264de3fc5234160e71d1b06aed

--- setup.py.orig	2020-05-07 15:34:11 UTC
+++ setup.py
@@ -62,7 +62,7 @@ exec(open('moviepy/version.py').read()) # loads __vers
 
 # Define the requirements for specific execution needs.
 requires = [
-    'decorator>=4.0.2,<5.0',
+    'decorator>=4.0.2,<6.0',
     "imageio>=2.5,<3.0; python_version>='3.4'",
     "imageio>=2.0,<2.5; python_version<'3.4'",
     "imageio_ffmpeg>=0.2.0; python_version>='3.4'",
