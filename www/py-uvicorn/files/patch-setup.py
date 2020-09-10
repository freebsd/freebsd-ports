Obtained from:	https://github.com/encode/uvicorn/commit/54d729ccc1638180a51e6ab600c4724e6424b048

--- setup.py.orig	2020-07-31 16:54:58 UTC
+++ setup.py
@@ -42,7 +42,7 @@ env_marker = (
 
 requirements = [
     "click==7.*",
-    "h11>=0.8,<0.10",
+    "h11>=0.8,<0.11",
     "websockets==8.*",
     "httptools==0.1.* ;" + env_marker,
     "uvloop>=0.14.0 ;" + env_marker,
