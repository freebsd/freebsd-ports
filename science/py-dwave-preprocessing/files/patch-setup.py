--- setup.py.orig	2022-12-25 07:50:44 UTC
+++ setup.py
@@ -26,6 +26,7 @@ extra_compile_args = {
     'msvc': ['/std:c++17', '/EHsc'],
     'unix': [
         '-std=c++17', 
+        '-DSPDLOG_FMT_EXTERNAL=1', 
        ],
 }
 
