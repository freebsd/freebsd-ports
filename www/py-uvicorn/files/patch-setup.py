--- setup.py.orig	2021-08-13 17:03:50 UTC
+++ setup.py
@@ -53,7 +53,7 @@ minimal_requirements = [
 
 extra_requirements = [
     "websockets>=9.1",
-    "httptools==0.2.*",
+    "httptools>=0.2.0,<0.4",
     "uvloop>=0.14.0,!=0.15.0,!=0.15.1; " + env_marker_cpython,
     "colorama>=0.4;" + env_marker_win,
     "watchgod>=0.6",
