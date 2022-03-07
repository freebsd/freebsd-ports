--- setup.py.orig	2022-02-16 12:54:46 UTC
+++ setup.py
@@ -53,7 +53,7 @@ minimal_requirements = [
 
 extra_requirements = [
     "websockets>=10.0",
-    "httptools>=0.2.0,<0.4.0",
+    "httptools>=0.2.0,<0.4.1",
     "uvloop>=0.14.0,!=0.15.0,!=0.15.1; " + env_marker_cpython,
     "colorama>=0.4;" + env_marker_win,
     "watchgod>=0.6",
