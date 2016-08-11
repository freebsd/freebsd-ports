--- setup.py.orig	2016-06-10 21:29:48 UTC
+++ setup.py
@@ -109,7 +109,7 @@ def get_version():
     version = '1.3'
     release = False
     if not release:
-        version += '-dev' + svn_version()
+        version += '-dev'
     return version
 
 def write_version_py(filename=os.path.join('pysparse', 'version.py')):
@@ -142,7 +142,6 @@ def setup_package():
             author_email = "{hamsel,d-orban,wd15}@sf.net,",
             maintainer = "PySparse Developers",
             maintainer_email = "{hamsel,d-orban,wd15}@sf.net,",
-            summary = "Fast sparse matrix library for Python",
             description = "Fast sparse matrix library for Python",
             long_description = "\n".join(DOCLINES[2:]),
             url = "pysparse.sf.net",
