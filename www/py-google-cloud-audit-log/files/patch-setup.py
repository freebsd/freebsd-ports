--- setup.py.orig	2026-03-30 22:16:48 UTC
+++ setup.py
@@ -58,7 +58,7 @@ setuptools.setup(
     long_description_content_type="text/markdown",
     install_requires=dependencies,
     license="Apache-2.0",
-    packages=find_namespace_packages(exclude=("tests*", "testing*")),
+    packages=find_namespace_packages(exclude=("docs", "docs.*", "tests*", "testing*")),
     python_requires=">=3.9",
     url="https://github.com/googleapis/python-audit-log",
     include_package_data=True,
