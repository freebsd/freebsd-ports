--- ./setup.py.orig	2013-06-20 10:29:51.598889219 +0300
+++ ./setup.py	2013-06-20 10:30:03.628888237 +0300
@@ -93,7 +93,7 @@
         license='MIT',
         py_modules=['pupynere'],
         include_package_data=True,
-        zip_safe=True,
+        zip_safe=False,
         test_suite = 'nose.collector',
         install_requires=[
             'numpy',
