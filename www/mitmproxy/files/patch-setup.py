--- setup.py.orig	2021-09-28 16:43:29 UTC
+++ setup.py
@@ -67,7 +67,7 @@ setup(
     # https://packaging.python.org/en/latest/requirements/#install-requires
     # It is not considered best practice to use install_requires to pin dependencies to specific versions.
     install_requires=[
-        "asgiref>=3.2.10,<3.5",
+        "asgiref>=3.2.10,<3.6",
         "blinker>=1.4, <1.5",
         "Brotli>=1.0,<1.1",
         "certifi>=2019.9.11",  # no semver here - this should always be on the last release!
@@ -83,7 +83,7 @@ setup(
         "passlib>=1.6.5, <1.8",
         "protobuf>=3.14,<3.19",
         "pyOpenSSL>=20.0,<20.1",
-        "pyparsing>=2.4.2,<2.5",
+        "pyparsing>=2.4.2,<3.1",
         "pyperclip>=1.6.0,<1.9",
         "ruamel.yaml>=0.16,<0.17.17",
         "sortedcontainers>=2.3,<2.5",
@@ -91,7 +91,7 @@ setup(
         "urwid>=2.1.1,<2.2",
         "wsproto>=1.0,<1.1",
         "publicsuffix2>=2.20190812,<3",
-        "zstandard>=0.11,<0.16",
+        "zstandard>=0.11,<0.18",
     ],
     extras_require={
         ':sys_platform == "win32"': [
