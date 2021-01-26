--- setup.py.orig	2021-01-14 10:34:05 UTC
+++ setup.py
@@ -39,7 +39,7 @@ setup(
         'isodate>=0.5.0',
         'lxml>=3.3.5',
         'xmlsec>=1.0.5',
-        'defusedxml==0.6.0'
+        'defusedxml>=0.6.0'
     ],
     dependency_links=['http://github.com/mehcode/python-xmlsec/tarball/master'],
     extras_require={
