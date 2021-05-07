--- setup.py.orig	2021-02-20 16:48:34 UTC
+++ setup.py
@@ -51,8 +51,8 @@ minimal_requirements = [
 
 
 extra_requirements = [
-    "websockets==8.*",
-    "httptools==0.1.* ;" + env_marker_cpython,
+    "websockets>=8.0",
+    "httptools>=0.1.0 ;" + env_marker_cpython,
     "uvloop>=0.14.0,!=0.15.0,!=0.15.1; " + env_marker_cpython,
     "colorama>=0.4;" + env_marker_win,
     "watchgod>=0.6",
