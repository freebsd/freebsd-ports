--- setup.py.orig	2023-11-11 01:20:49 UTC
+++ setup.py
@@ -48,7 +48,7 @@ setup(
     keywords=["markup", "markdown", "commonmark"],
     entry_points={
         'console_scripts': [
-            'cmark = commonmark.cmark:main',
+            'cmark-py = commonmark.cmark:main',
         ]
     },
     cmdclass={'test': Test},
