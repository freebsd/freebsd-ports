--- setup.py.orig	2015-08-06 17:43:56 UTC
+++ setup.py
@@ -39,15 +39,17 @@ import turses
 NAME = "turses"
 
 REQUIREMENTS = [
-    "urwid==1.3.0",
-    "tweepy==3.3.0",
-    "future==0.14.3",
+    "urwid>=1.3.0",
+    "tweepy>=3.3.0",
+    "future>=0.14.3",
 ]
 if version_info[:2] == (2, 6):
     REQUIREMENTS.append("argparse")
 
-TEST_REQUIREMENTS = list(REQUIREMENTS)
-TEST_REQUIREMENTS.extend(["mock", "pytest", "coverage", "tox"])
+TEST_REQUIREMENTS = [
+    "mock",
+    "nose"
+]
 
 try:
     long_description = open("README.rst").read() + "\n\n" + open(
