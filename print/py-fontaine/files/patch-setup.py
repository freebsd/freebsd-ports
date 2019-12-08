--- setup.py.orig	2019-10-18 01:03:28 UTC
+++ setup.py
@@ -19,7 +19,7 @@ with open("README.rst", 'r', encoding='u
     readme = readme_file.read()
 
 setup(name='fontaine',
-      use_scm_version={"write_to": "fontaine/_version.py"},
+      use_scm_version={"fallback_version": "%%PORTVERSION%%", "write_to": "fontaine/_version.py"},
       description='Font analysis tool for determining character/glyph support',
       license="GNU GPLv3",
       long_description=readme,
