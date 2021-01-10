--- setup.py.orig	2020-02-18 21:42:18 UTC
+++ setup.py
@@ -66,7 +66,6 @@ def setup_package():
         download_url="https://pypi.org/project/" + package,
         maintainer="James D. Gaboardi",
         maintainer_email="jgaboardi@gmail.com",
-        setup_requires=["pytest-runner"],
         tests_require=["pytest"],
         keywords="spatial statistics, networks, graphs",
         classifiers=[
