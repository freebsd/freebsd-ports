Avoid the installation of the test suite in the top-level directory
of ${PYTHON_SITELIBDIR}.

--- setup.py.orig	2024-02-12 05:03:25 UTC
+++ setup.py
@@ -14,7 +14,7 @@ setup(
     author="Patrick Lauber",
     author_email="digi@treepy.com",
     url="https://github.com/jazzband/django-smart-selects",
-    packages=find_packages(),
+    packages=find_packages(exclude=['test_app*']),
     include_package_data=True,
     python_requires=">=3.6",
     install_requires=["django>=2.2"],
