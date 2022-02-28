--- setup.py.orig	2022-02-28 05:29:01 UTC
+++ setup.py
@@ -0,0 +1,41 @@
+# Generated via pdm export -f setuppy" (run "pdm lock" beforehand)
+# -*- coding: utf-8 -*-
+from setuptools import setup
+
+INSTALL_REQUIRES = [
+    'Jinja2>=2.11.1',
+    'Markdown>=3.3',
+    'MarkupSafe>=1.1',
+    'mkdocs>=1.2',
+    'mkdocs-autorefs>=0.1',
+    'pymdown-extensions>=6.3',
+    'pytkdocs>=0.14.0',
+]
+ENTRY_POINTS = {
+    'mkdocs.plugins': [
+        'mkdocstrings = mkdocstrings.plugin:MkdocstringsPlugin',
+    ],
+}
+
+setup_kwargs = {
+    'name': 'mkdocstrings',
+    'version': '%%DISTVERSION%%',
+    'description': 'Automatic documentation from sources, for MkDocs.',
+    'author': '',
+    'author_email': 'Timothée Mazzucotelli <pawamoy@pm.me>',
+    'package_dir': {'': 'src/'},
+    'packages': [
+        'mkdocstrings',
+        'mkdocstrings.handlers',
+        'mkdocstrings.templates.python',
+        'mkdocstrings.templates.python.material',
+        'mkdocstrings.templates.python.mkdocs',
+        'mkdocstrings.templates.python.readthedocs'
+    ],
+    'package_data': {'': ['*']},
+    'install_requires': INSTALL_REQUIRES,
+    'python_requires': '>=3.6.2',
+    'entry_points': ENTRY_POINTS,
+}
+
+setup(**setup_kwargs)
