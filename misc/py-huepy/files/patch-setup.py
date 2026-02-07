--- setup.py.orig	2019-12-19 05:42:39 UTC
+++ setup.py
@@ -30,7 +30,6 @@ setup(
     keywords='hue, color, terminal color, colorama',
     packages=find_packages(),
     py_modules=['huepy'],
-    data_files=[('', ['LICENSE'])],
     include_package_data=True,
     classifiers=[
         'License :: OSI Approved :: GNU General Public License v3 (GPLv3)',
