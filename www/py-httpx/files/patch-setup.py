--- setup.py.orig	2022-01-26 14:49:48 UTC
+++ setup.py
@@ -59,7 +59,7 @@ setup(
         "certifi",
         "charset_normalizer",
         "sniffio",
-        "rfc3986[idna2008]>=1.3,<2",
+        "rfc3986[idna2008]>=1.3",
         "httpcore>=0.14.5,<0.15.0",
         "async_generator; python_version < '3.7'"
     ],
@@ -72,7 +72,7 @@ setup(
         ],
         "cli": [
             "click==8.*",
-            "rich==10.*",
+            "rich==11.*",
             "pygments==2.*"
         ]
     },
