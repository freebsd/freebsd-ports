--- setup.py.orig	2021-05-23 05:55:52 UTC
+++ setup.py
@@ -27,7 +27,7 @@ setup(
     long_description=readme,
     long_description_content_type="text/markdown",
     python_requires=">=3.6",
-    packages=find_packages(exclude=["docs", ".gitignore", "README.md"]),
+    packages=find_packages(exclude=["docs", "tests", ".gitignore", "README.md"]),
     install_requires=required,
     classifiers=[
         "Environment :: Console",
