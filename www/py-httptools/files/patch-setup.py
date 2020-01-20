--- setup.py.orig	2019-02-25 19:55:33 UTC
+++ setup.py
@@ -26,8 +26,7 @@ setup(
     packages=['httptools', 'httptools.parser'],
     ext_modules=[
         Extension("httptools.parser.parser",
-                  ["httptools/parser/parser.c",
-                   "vendor/http-parser/http_parser.c"],
+                  ["httptools/parser/parser.c"],
                   extra_compile_args=['-O2'])
     ],
     provides=['httptools'],
