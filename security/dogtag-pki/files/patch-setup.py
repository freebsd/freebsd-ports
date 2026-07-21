--- setup.py.orig	2025-08-05 19:20:05 UTC
+++ setup.py
@@ -48,8 +48,8 @@ setup(
 setup(
     author='Dogtag Certificate System Team',
     author_email='devel@lists.dogtagpki.org',
-    name='Dogtag PKI',
-    version='10',
+    name='dogtag-pki',
+    version='11.7.0',
     description='Dogtag Certificate System',
     license='GPL',
     keywords='pki',
@@ -66,7 +66,7 @@ setup(
         'pki.server.deployment',
         'pki.server.deployment.scriptlets',
     ],
-    data_files=list(upgrades.items()),
+    data_files=[],
     classifiers=[
         'Development Status :: 5 - Production/Stable',
         'Environment :: Web Environment',
