--- setup.py.orig	2018-02-22 19:44:17 UTC
+++ setup.py
@@ -34,7 +34,6 @@ setuptools.setup(
     long_description='Google Compute Engine guest environment.',
     name='google-compute-engine',
     packages=setuptools.find_packages(),
-    scripts=glob.glob('scripts/*'),
     url='https://github.com/GoogleCloudPlatform/compute-image-packages',
     version='2.7.6',
     # Entry points create scripts in /usr/bin that call a function.
