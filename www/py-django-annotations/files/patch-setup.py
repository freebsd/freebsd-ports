--- setup.py.orig	2016-04-14 21:10:12 UTC
+++ setup.py
@@ -0,0 +1,10 @@
+#!/usr/bin/env python
+
+from distutils.core import setup
+
+setup(name='django-annotations',
+      version='0.0.0.2016041401',
+      packages=['annotation/migrations', 'annotation', 'annotator/settings', 'annotator', 'enqueue/migrations', 'enqueue'],
+      scripts=['annotations.py'],
+      package_data={'annotation': ['static/js/annotator.min.js', 'templates/*']},
+)
