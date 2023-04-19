--- setup.py.orig	2023-03-03 17:20:04 UTC
+++ setup.py
@@ -23,7 +23,7 @@ except IOError:
 
 setup(
     name="fontbakery",
-    use_scm_version={"write_to": "Lib/fontbakery/_version.py"},
+    use_scm_version={"fallback_version": "%%PORTVERSION%%", "write_to": "Lib/fontbakery/_version.py"},
     url='https://github.com/googlefonts/fontbakery/',
     description='Well designed Font QA tool, written in Python 3',
     long_description=readme,
@@ -66,7 +66,7 @@ setup(
         'beautifulsoup4',
         'beziers>=0.5.0', # Uses new fontTools glyph outline access
         'cmarkgfm',
-        'collidoscope==0.4.1', # 0.4.0 had a bug that failed to detect
+        'collidoscope>=0.5.2', # 0.4.0 had a bug that failed to detect
                                # an ïï collision on Nunito Black.
                                # (see https://github.com/googlefonts/fontbakery/issues/3554)
         'defcon',
@@ -84,7 +84,7 @@ setup(
         'pip-api',    # needed for checking Font Bakery's version
         # 3.7.0 fixed a bug on parsing some METADATA.pb files.
         # We cannot use v4 because our protobuf files have been compiled with v3.
-        'protobuf>=3.7.0, <4',  
+        'protobuf>=3.7.0',  
                             # (see https://github.com/googlefonts/fontbakery/issues/2200)
         'PyYAML',
         'requests',
