--- ./setup.py.orig	2013-12-19 01:59:57.000000000 +0000
+++ ./setup.py	2014-02-22 15:06:23.000000000 +0000
@@ -55,10 +55,10 @@
       "Topic :: Communications"
     ],
     include_package_data=True,
-    packages=find_packages(),
+    packages=find_packages(exclude=('turpial.ui.unity', 'turpial.ui.gtk.*', 'turpial.ui.gtk')),
     package_data={
       'turpial': ['data/pixmaps/*', 'data/sounds/*', 'data/fonts/*', 'turpial/ui/qt/*',
-          'turpial/i18n/*', 'turpial/ui/qt/templates/*'],
+          'turpial/ui/qt/templates/*'],
     },
     entry_points={
       'console_scripts': [
