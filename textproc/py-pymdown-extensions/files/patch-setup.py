Generated via adding

[tool.hatch.build.targets.sdist]
support-legacy = true

to setup.py and then run "hatchling build".

--- setup.py.orig	2022-11-19 11:48:49 UTC
+++ setup.py
@@ -0,0 +1,32 @@
+# -*- coding: utf-8 -*-
+from setuptools import setup
+
+setup(
+    name='pymdown-extensions',
+    version='%%DISTVERSION%%',
+    description='Extension pack for Python Markdown.',
+    long_description='',
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
+    install_requires=[
+        'markdown>=3.2',
+    ],
+    packages=[
+        'pymdownx',
+    ],
+)
