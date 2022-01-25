--- setup.py.orig	2022-01-15 23:40:48 UTC
+++ setup.py
@@ -16,7 +16,6 @@ setup(
     url="https://github.com/dmulyalin/ttp",
     packages=find_packages(),
     include_package_data=True,
-    data_files=[("", ["LICENSE"])],
     classifiers=[
         "Topic :: Utilities",
         "Programming Language :: Python :: 2.7",
