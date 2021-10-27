Avoid the installation of the test suite in the top-level directory
of ${PYTHON_SITELIBDIR}.

--- setup.py.orig	2021-09-12 11:44:16 UTC
+++ setup.py
@@ -33,7 +33,7 @@ setup(
     author=u'James Oakley',
     author_email='jfunk@funktronics.ca',
 
-    packages=find_packages(),
+    packages=find_packages(exclude=['test*']),
     include_package_data=True,
     zip_safe=False,
     install_requires=requirements,
