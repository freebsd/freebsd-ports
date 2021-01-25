Avoid the installation of the test suite in the top-level directory
of ${PYTHON_SITELIBDIR}.

--- setup.py.orig	2020-11-24 12:09:27 UTC
+++ setup.py
@@ -43,7 +43,7 @@ setup(
     license='BSD-3-Clause',
     description='Adds pretty CSS styles for the django CMS admin interface.',
     long_description=open('README.rst').read(),
-    packages=find_packages(exclude=['preview']),
+    packages=find_packages(exclude=['preview', 'tests']),
     include_package_data=True,
     zip_safe=False,
     install_requires=REQUIREMENTS,
