Remove py-pytest-runner as build time dependency because it is deprecated and
should be no longer used.

--- setup.py.orig	2024-10-01 12:41:04 UTC
+++ setup.py
@@ -40,7 +40,6 @@ setup(
     long_description=LONG_DESCRIPTION,
     long_description_content_type="text/markdown",
     tests_require=["pytest", "pytest-django"],
-    setup_requires=["pytest-runner"],
     options={"bdist_wheel": {"universal": "1"}},
     install_requires=[
         "prometheus-client>=0.7",
