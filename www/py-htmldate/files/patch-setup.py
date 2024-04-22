--- setup.py.orig	2024-01-17 16:57:16 UTC
+++ setup.py
@@ -120,7 +120,7 @@ setup(
         "dateparser >= 1.1.2",  # 1.1.3+ slower
         # see tests on Github Actions
         "lxml == 4.9.2; platform_system == 'Darwin' and python_version <= '3.8'",
-        "lxml >= 4.9.4, < 6; platform_system != 'Darwin' or python_version > '3.8'",
+        "lxml >= 4.9.3, < 6; platform_system != 'Darwin' or python_version > '3.8'",
         "python-dateutil >= 2.8.2",
         "urllib3 >= 1.26, < 2; python_version < '3.7'",
         "urllib3 >= 1.26, < 3; python_version >= '3.7'",
