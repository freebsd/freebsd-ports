--- setup.py.orig	2022-02-28 05:25:48 UTC
+++ setup.py
@@ -0,0 +1,41 @@
+# Generated via "pdm export -f setuppy" (run "pdm lock" beforehand)
+#
+# -*- coding: utf-8 -*-
+from setuptools import setup
+
+INSTALL_REQUIRES = [
+    "astunparse>=1.6; python_version < '3.9'",
+    "cached-property>=1.5; python_version < '3.8'",
+    "typing-extensions>=3.7; python_version < '3.8'",
+]
+EXTRAS_REQUIRE = {
+    'numpy-style': [
+        'docstring_parser>=0.7',
+    ],
+}
+ENTRY_POINTS = {
+    'console_scripts': [
+        'pytkdocs = pytkdocs.cli:main',
+    ],
+}
+
+setup_kwargs = {
+    'name': 'pytkdocs',
+    'version': '%%DISTVERSION%%',
+    'description': 'Load Python objects documentation.',
+    'author': '',
+    'author_email': 'Timothée Mazzucotelli <pawamoy@pm.me>',
+    'packages': [
+        'pytkdocs',
+        'pytkdocs.parsers',
+        'pytkdocs.parsers.docstrings',
+    ],
+    'package_dir': {'': 'src'},
+    'package_data': {'': ['*']},
+    'install_requires': INSTALL_REQUIRES,
+    'extras_require': EXTRAS_REQUIRE,
+    'python_requires': '>=3.7',
+    'entry_points': ENTRY_POINTS,
+}
+
+setup(**setup_kwargs)
