--- setup.py.orig	2020-10-08 12:15:02 UTC
+++ setup.py
@@ -61,7 +61,7 @@ setup(
         "httpcore==0.12.*",
     ],
     extras_require={
-        "http2": "h2==3.*",
+        "http2": "h2>=3,<5",
         "brotli": "brotlipy==0.7.*",
     },
     classifiers=[
