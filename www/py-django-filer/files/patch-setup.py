Relax requirements for www/py-django-polymorphic and avoid the installation of
the test suite in the top-level directory of ${PYTHON_SITELIBDIR}.

--- setup.py.orig	2021-11-09 13:48:04 UTC
+++ setup.py
@@ -7,7 +7,7 @@ from filer import __version__
 REQUIREMENTS = [
     'django>=2.2,<4.0',
     'django-mptt>=0.6,<1.0',  # the exact version depends on Django
-    'django-polymorphic>=2,<3.1',
+    'django-polymorphic>=2',
     'easy-thumbnails>=2.8.0',
     'Unidecode>=0.04,<1.2',
 ]
@@ -51,7 +51,7 @@ setup(
     description='A file management application for django that makes handling '
                 'of files and images a breeze.',
     long_description=open('README.rst').read(),
-    packages=find_packages(),
+    packages=find_packages(exclude=['tests*']),
     include_package_data=True,
     zip_safe=False,
     install_requires=REQUIREMENTS,
