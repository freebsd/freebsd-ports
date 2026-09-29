--- setup.py.orig	2023-05-28 18:25:53 UTC
+++ setup.py
@@ -23,7 +23,6 @@ setup(
     install_requires=["requests", "urllib3>=1.26"],
     extras_require={"test": test_requires},
     tests_require=test_requires,
-    setup_requires=["pytest-runner"],
     classifiers=[
         "Development Status :: 5 - Production/Stable",
         "Intended Audience :: Developers",
