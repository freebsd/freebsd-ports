--- setup.py.orig	2020-03-29 00:21:04 UTC
+++ setup.py
@@ -74,7 +74,6 @@ def setup_package():
         license="BSD",
         py_modules=["libpysal"],
         packages=find_packages(),
-        setup_requires=["pytest-runner"],
         tests_require=["pytest"],
         keywords="spatial statistics",
         classifiers=[
