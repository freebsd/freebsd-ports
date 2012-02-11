--- setup.py.orig	2011-07-24 22:22:22.000000000 +0200
+++ setup.py	2011-12-05 20:18:49.000000000 +0100
@@ -54,8 +54,8 @@
     version=VERSION,
     package_dir={'':'src'},
     packages=find_packages('src'),
-    test_suite='tests', #'nose.collector'
-    tests_require='mock',
+    #test_suite='tests', #'nose.collector'
+    #tests_require='mock',
     entry_points={
         'console_scripts': [
             'csscapture = cssutils.scripts.csscapture:main',
@@ -70,6 +70,7 @@
     url='http://cthedot.de/cssutils/',
     download_url='http://code.google.com/p/cssutils/downloads/list',
     license='LGPL 2.1 or later, see also http://cthedot.de/cssutils/',
+    zip_safe=True,
     keywords='CSS, Cascading Style Sheets, CSSParser, DOM Level 2 Stylesheets, DOM Level 2 CSS',
     platforms='Python 2.5 and later.',
     cmdclass=dict(
