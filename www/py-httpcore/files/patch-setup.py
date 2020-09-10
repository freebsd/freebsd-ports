--- setup.py.orig	2020-08-20 09:34:45 UTC
+++ setup.py
@@ -53,7 +53,7 @@ setup(
     packages=get_packages("httpcore"),
     include_package_data=True,
     zip_safe=False,
-    install_requires=["h11>=0.8,<0.10", "sniffio==1.*"],
+    install_requires=["h11>=0.8,<0.11", "sniffio==1.*"],
     extras_require={
         "http2": ["h2==3.*"],
     },
