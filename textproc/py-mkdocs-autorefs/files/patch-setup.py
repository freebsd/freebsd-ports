--- setup.py.orig	2022-03-22 06:18:53 UTC
+++ setup.py
@@ -0,0 +1,32 @@
+# Generated via "pdm export -f setuppy" (run "pdm lock" beforehand)
+#
+# -*- coding: utf-8 -*-
+from setuptools import setup
+
+INSTALL_REQUIRES = [
+    'Markdown>=3.3',
+    'mkdocs>=1.1',
+]
+ENTRY_POINTS = {
+    'mkdocs.plugins': [
+        'autorefs = mkdocs_autorefs.plugin:AutorefsPlugin',
+    ],
+}
+
+setup_kwargs = {
+    'name': 'mkdocs-autorefs',
+    'version': '%%DISTVERSION%%',
+    'description': 'Automatically link across pages in MkDocs.',
+    'author': '',
+    'author_email': 'Oleh Prypin <oleh@pryp.in>,Timothée Mazzucotelli <pawamoy@pm.me>',
+    'packages': [
+        'mkdocs_autorefs',
+    ],
+    'package_dir': {'': 'src'},
+    'package_data': {'': ['*']},
+    'install_requires': INSTALL_REQUIRES,
+    'python_requires': '>=3.7',
+    'entry_points': ENTRY_POINTS,
+}
+
+setup(**setup_kwargs)
