--- setup.py.orig	2018-05-20 14:27:17 UTC
+++ setup.py
@@ -55,11 +55,11 @@ verification.""",
             'dknewkey = dkim.dknewkey:main'
         ],
     },
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
