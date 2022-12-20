Generated via adding

[tool.hatch.build.targets.sdist]
support-legacy = true

to setup.py and then run "hatchling build".

--- setup.py.orig	2022-12-20 10:46:10 UTC
+++ setup.py
@@ -0,0 +1,42 @@
+# -*- coding: utf-8 -*-
+from setuptools import setup
+
+setup(
+    name='mkdocs-material',
+    version='%%DISTVERSION%%',
+    description='Documentation that simply works',
+    long_description='',
+    author_email='Martin Donath <martin.donath@squidfunk.com>',
+    classifiers=[
+        'Development Status :: 5 - Production/Stable',
+        'Environment :: Web Environment',
+        'License :: OSI Approved :: MIT License',
+        'Programming Language :: JavaScript',
+        'Programming Language :: Python',
+        'Topic :: Documentation',
+        'Topic :: Software Development :: Documentation',
+        'Topic :: Text Processing :: Markup :: HTML',
+    ],
+    install_requires=[
+        'jinja2>=3.0.2',
+        'markdown>=3.2',
+        'mkdocs-material-extensions>=1.1',
+        'mkdocs>=1.4.0',
+        'pygments>=2.12',
+        'pymdown-extensions>=9.4',
+        'requests>=2.26',
+    ],
+    entry_points={
+        'mkdocs.plugins': [
+            'search = material.plugins.search.plugin:SearchPlugin',
+            'social = material.plugins.social.plugin:SocialPlugin',
+            'tags = material.plugins.tags.plugin:TagsPlugin',
+        ],
+        'mkdocs.themes': [
+            'material = material',
+        ],
+    },
+    package_data={
+        '': ['*', '.icons/*', '.icons/*/*', '.icons/*/*/*'],
+    },
+)
