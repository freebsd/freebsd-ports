- remove bogus paths causing build failure

--- python/setup.py.orig	2025-03-25 06:05:42 UTC
+++ python/setup.py
@@ -75,9 +75,7 @@ def get_lib_path():
             "web",
             "rust",
             "golang",
-            "include",
             "src",
-            "cmake",
             "CMakeLists.txt",
         ]:
             for name in lib_path:
