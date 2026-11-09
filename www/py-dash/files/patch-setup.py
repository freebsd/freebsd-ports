--- setup.py.orig	2026-10-29 20:08:03 UTC
+++ setup.py
@@ -17,7 +17,7 @@ setup(
     version=main_ns["__version__"],
     author="Chris Parmer",
     author_email="chris@plotly.com",
-    packages=find_packages(exclude=["tests*"]),
+    packages=find_packages(exclude=["benchmarks", "benchmarks.*", "tests*"]),
     include_package_data=True,
     license="MIT",
     description=(
