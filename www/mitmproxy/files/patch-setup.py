--- setup.py.orig	2019-02-14 12:22:24 UTC
+++ setup.py
@@ -61,7 +61,7 @@ setup(
     # It is not considered best practice to use install_requires to pin dependencies to specific versions.
     install_requires=[
         "blinker>=1.4",
-        "brotli>=0.7.0,<0.8",
+        "brotli>=0.7.0",
         "certifi>=2015.11.20.1",  # no semver here - this should always be on the last release!
         "click>=6.2",
         "cryptography>=2.1.4,<2.4",
@@ -75,10 +75,10 @@ setup(
         "pyparsing>=2.1.3",
         "pyperclip>=1.6.0",
         "ruamel.yaml>=0.13.2",
-        "sortedcontainers>=1.5.4,<2.1",
+        "sortedcontainers>=1.5.4",
         "tornado>=4.3,<5.2",
         "urwid>=2.0.1,<2.1",
-        "wsproto>=0.11.0,<0.12.0",
+        "wsproto>=0.13.0",
     ],
     extras_require={
         ':sys_platform == "win32"': [
