Generated via adding

[tool.hatch.build.targets.sdist]
support-legacy = true

to setup.py and then run "hatchling build".

--- setup.py.orig	2022-12-20 11:05:40 UTC
+++ setup.py
@@ -0,0 +1,29 @@
+# -*- coding: utf-8 -*-
+from setuptools import setup
+
+setup(
+    name='mkdocs-material-extensions',
+    version='%%DISTVERSION%%',
+    description='Extension pack for Python Markdown and MkDocs Material.',
+    long_description="",
+    author_email='Isaac Muse <Isaac.Muse@gmail.com>',
+    classifiers=[
+        'Development Status :: 5 - Production/Stable',
+        'Environment :: Console',
+        'Intended Audience :: Developers',
+        'License :: OSI Approved :: MIT License',
+        'Operating System :: OS Independent',
+        'Programming Language :: Python :: 3',
+        'Programming Language :: Python :: 3.7',
+        'Programming Language :: Python :: 3.8',
+        'Programming Language :: Python :: 3.9',
+        'Programming Language :: Python :: 3.10',
+        'Topic :: Internet :: WWW/HTTP :: Dynamic Content',
+        'Topic :: Software Development :: Libraries :: Python Modules',
+        'Topic :: Text Processing :: Filters',
+        'Topic :: Text Processing :: Markup :: HTML',
+    ],
+    packages=[
+        'materialx',
+    ],
+)
