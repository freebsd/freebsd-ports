--- setup.py.orig	2021-12-17 07:16:14 UTC
+++ setup.py
@@ -24,7 +24,7 @@ with open('README.md') as f:
 
 setup(
     name="glyphsets",
-    use_scm_version={"write_to": "Lib/glyphsets/_version.py"},
+    use_scm_version={"fallback_version": "%%PORTVERSION%%", "write_to": "Lib/glyphsets/_version.py"},
     url='https://github.com/googlefonts/glyphsets/',
     description='A python API for evaluating coverage of glyph sets in font projects.',
     long_description=long_description,
@@ -52,7 +52,7 @@ setup(
         'Programming Language :: Python :: 3'
     ],
     python_requires=">=3.7",
-    setup_requires=['setuptools_scm>=4,<6.1'],
+    setup_requires=['setuptools_scm>=4'],
     install_requires=[
         'setuptools',
         'FontTools[ufo]',
