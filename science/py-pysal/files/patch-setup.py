--- setup.py.orig	2020-02-01 23:18:07 UTC
+++ setup.py
@@ -54,7 +54,7 @@ def setup_package():
         download_url='https://pypi.python.org/pypi/pysal',
         license='BSD',
         packages=find_packages(),
-        python_requires='>3.6',
+        python_requires='>=3.6',
         test_suite='nose.collector',
         tests_require=['nose'],
         keywords='spatial statistics',
