--- setup.py.orig	2021-04-29 12:57:41 UTC
+++ setup.py
@@ -63,7 +63,7 @@ setup(
         "async_generator; python_version < '3.7'"
     ],
     extras_require={
-        "http2": "h2==3.*",
+        "http2": "h2>=3,<5",
         "brotli": "brotlicffi==1.*",
     },
     classifiers=[
