--- setup.py.orig	2018-02-10 07:29:15 UTC
+++ setup.py
@@ -41,11 +41,11 @@ verification.""",
     packages = ["dkim"],
     scripts = ["arcsign.py", "arcverify.py", "dknewkey.py", "dkimsign.py",
         "dkimverify.py"],
-    data_files = [(os.path.join('share', 'man', 'man1'),
-        ['man/arcsign.1']), (os.path.join('share', 'man', 'man1'),
-        ['man/arcverify.1']),(os.path.join('share', 'man', 'man1'),
-        ['man/dkimsign.1']), (os.path.join('share', 'man', 'man1'),
-        ['man/dkimverify.1']),(os.path.join('share', 'man', 'man1'),
+    data_files = [(os.path.join('man', 'man1'),
+        ['man/arcsign.1']), (os.path.join('man', 'man1'),
+        ['man/arcverify.1']),(os.path.join('man', 'man1'),
+        ['man/dkimsign.1']), (os.path.join('man', 'man1'),
+        ['man/dkimverify.1']),(os.path.join('man', 'man1'),
         ['man/dknewkey.1']),],
     classifiers = [
       'Development Status :: 5 - Production/Stable',
