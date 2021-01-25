Avoid the installation of the test suite in the top-level directory
of ${PYTHON_SITELIBDIR}.

See also: https://github.com/django-cms/django-classy-tags/issues/58

--- setup.py.orig	2020-08-26 08:49:51 UTC
+++ setup.py
@@ -41,7 +41,7 @@ setup(
     license='BSD',
     description='Class based template tags for Django',
     long_description=open('README.rst').read(),
-    packages=find_packages(),
+    packages=find_packages(exclude=("tests",)),
     include_package_data=True,
     zip_safe=False,
     install_requires=REQUIREMENTS,
