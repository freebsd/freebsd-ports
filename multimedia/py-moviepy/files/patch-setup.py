--- setup.py.orig	2020-03-24 20:20:07 UTC
+++ setup.py
@@ -67,7 +67,7 @@ requires = [
     "imageio>=2.0,<2.5; python_version<'3.4'",
     "imageio_ffmpeg>=0.2.0; python_version>='3.4'",
     'tqdm>=4.11.2,<5.0',
-    "numpy>=1.17.3; python_version!='2.7'",
+    "numpy>=0; python_version!='2.7'",
     "numpy; python_version>='2.7'",
     'requests>=2.8.1,<3.0',
     'proglog<=1.0.0'
