--- setup.py.orig	2014-08-11 10:12:36 UTC
+++ setup.py
@@ -53,12 +53,12 @@ try:
             "django >= 1.4.10, != 1.6.0, < 1.7",
             "filebrowser_safe >= 0.3.4",
             "grappelli_safe >= 0.3.12",
-            "tzlocal == 1.0",
+            "tzlocal >= 1.0",
             "bleach >= 1.4",
-            "beautifulsoup4 == 4.1.3",
+            "beautifulsoup4 >= 4.1.3",
             "requests >= 2.1.0",
             "requests-oauthlib >= 0.4",
-            "future == 0.9.0",
+            "future >= 0.9.0",
             "pillow",
         ],
         entry_points="""
@@ -66,7 +66,7 @@ try:
             mezzanine-project=mezzanine.bin.mezzanine_project:create_project
         """,
         test_suite="mezzanine.bin.runtests.main",
-        tests_require=["pyflakes==0.6.1", "pep8==1.4.1"],
+        tests_require=["pyflakes>=0.6.1", "pep8>=1.4.1"],
         classifiers=[
             "Development Status :: 5 - Production/Stable",
             "Environment :: Web Environment",
