--- setup.py.orig	2021-06-30 07:08:47 UTC
+++ setup.py
@@ -91,7 +91,7 @@ setup(
         "urwid>=2.1.1,<2.2",
         "wsproto>=1.0,<1.1",
         "publicsuffix2>=2.20190812,<3",
-        "zstandard>=0.11,<0.15",
+        "zstandard>=0.11,<0.16",
     ],
     extras_require={
         ':sys_platform == "win32"': [
