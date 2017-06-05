--- setup.py.orig	2017-05-22 18:44:24 UTC
+++ setup.py
@@ -123,7 +123,7 @@ setup(
         'Operating System :: OS Independent',
         'Programming Language :: Python',
     ],
-    packages=find_packages('.', exclude=[u'tests', u'tests.*', u'tools']),
+    packages=find_packages('.', exclude=[u'tests', u'tests.*', u'tools', u'utils']),
     package_dir={'artifacts': 'artifacts'},
     data_files=[
         ('share/artifacts', glob.glob(os.path.join('data', '*'))),
