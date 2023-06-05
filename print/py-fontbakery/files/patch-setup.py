--- setup.py.orig	2023-06-01 00:42:56 UTC
+++ setup.py
@@ -23,7 +23,7 @@ except IOError:
 
 setup(
     name="fontbakery",
-    use_scm_version={"write_to": "Lib/fontbakery/_version.py"},
+    use_scm_version={"fallback_version": "%%PORTVERSION%%", "write_to": "Lib/fontbakery/_version.py"},
     url='https://github.com/googlefonts/fontbakery/',
     description='Well designed Font QA tool, written in Python 3',
     long_description=readme,
@@ -83,7 +83,7 @@ setup(
         'pip-api',    # needed for checking Font Bakery's version
         # 3.7.0 fixed a bug on parsing some METADATA.pb files.
         # We cannot use v4 because our protobuf files have been compiled with v3.
-        'protobuf>=3.7.0, <4',  
+        'protobuf>=3.7.0',  
                             # (see https://github.com/googlefonts/fontbakery/issues/2200)
         'PyYAML',
         'requests',
