--- setup.py.orig	2018-06-11 23:51:09 UTC
+++ setup.py
@@ -34,7 +34,6 @@ setuptools.setup(
     long_description='Google Compute Engine guest environment.',
     name='google-compute-engine',
     packages=setuptools.find_packages(),
-    scripts=glob.glob('scripts/*'),
     url='https://github.com/GoogleCloudPlatform/compute-image-packages',
     version='2.8.3',
     # Entry points create scripts in /usr/bin that call a function.
