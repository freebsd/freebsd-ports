--- setup.py.orig	2019-12-21 04:47:47 UTC
+++ setup.py
@@ -23,7 +23,7 @@ except IOError:
 
 setup(
     name="fontbakery",
-    use_scm_version={"write_to": "Lib/fontbakery/_version.py"},
+    use_scm_version={"fallback_version": "%%PORTVERSION%%", "write_to": "Lib/fontbakery/_version.py"},
     url='https://github.com/googlefonts/fontbakery/',
     description='Well designed Font QA tool, written in Python 3',
     long_description=readme,
