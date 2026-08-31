--- setup.py.orig	2026-08-06 05:54:32 UTC
+++ setup.py
@@ -57,7 +57,7 @@ setuptools.setup(
     long_description_content_type="text/markdown",
     install_requires=dependencies,
     license="Apache-2.0",
-    packages=find_namespace_packages(exclude=("tests*", "testing*")),
+    packages=find_namespace_packages(exclude=("docs", "docs.*", "tests*", "testing*")),
     python_requires=">=3.10",
     url="https://github.com/googleapis/google-cloud-python/tree/main/packages/google-cloud-audit-log",
     include_package_data=True,
