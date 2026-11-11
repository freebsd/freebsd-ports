* Remove py-pytest-runner as build time dependency because it is deprecated and
  should be no longer used.

* Relax upper bound of Django

--- setup.py.orig	2026-05-26 19:03:33 UTC
+++ setup.py
@@ -42,10 +42,9 @@ setup(
     long_description=LONG_DESCRIPTION,
     long_description_content_type="text/markdown",
     tests_require=["pytest", "pytest-django"],
-    setup_requires=["pytest-runner"],
     options={"bdist_wheel": {"universal": "1"}},
     install_requires=[
-        "Django>=4.2,<6.1,!=5.0.*",
+        "Django>=4.2,<6.2,!=5.0.*",
         "prometheus-client>=0.7",
     ],
     classifiers=[
