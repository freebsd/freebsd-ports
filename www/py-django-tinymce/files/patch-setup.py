Avoid the installation of the test suite in the top-level directory
of ${PYTHON_SITELIBDIR}.

https://github.com/jazzband/django-tinymce/issues/355

--- setup.py.orig	2021-11-30 16:45:41 UTC
+++ setup.py
@@ -21,7 +21,7 @@ CHANGELOG = read_file("CHANGELOG.rst")
 setup(
     name="django-tinymce",
     version="3.4.0",
-    packages=find_packages(),
+    packages=find_packages(exclude=['tests*']),
     include_package_data=True,
     author="Aljosa Mohorovic",
     author_email="aljosa.mohorovic@gmail.com",
