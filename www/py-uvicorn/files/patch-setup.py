--- setup.py.orig	2020-09-28 09:57:54 UTC
+++ setup.py
@@ -55,7 +55,7 @@ extra_requirements = [
     "uvloop>=0.14.0 ;" + env_marker_cpython,
     "colorama>=0.4.*;" + env_marker_win,
     "watchgod>=0.6,<0.7",
-    "python-dotenv==0.13.*",
+    "python-dotenv>=0.13.0",
     "PyYAML>=5.1",
 ]
 
