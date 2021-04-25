--- setup.py.orig	2021-03-15 09:19:02 UTC
+++ setup.py
@@ -59,10 +59,10 @@ setup(
         "certifi",
         "sniffio",
         "rfc3986[idna2008]>=1.3,<2",
-        "httpcore>=0.12.1,<0.13",
+        "httpcore>=0.12.1,<0.14",
     ],
     extras_require={
-        "http2": "h2==3.*",
+        "http2": "h2>=3,<5",
         "brotli": "brotlipy==0.7.*",
     },
     classifiers=[
