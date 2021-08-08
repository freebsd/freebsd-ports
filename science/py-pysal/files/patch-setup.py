--- setup.py.orig	2021-01-31 21:39:53 UTC
+++ setup.py
@@ -65,7 +65,7 @@ def setup_package():
         download_url='https://pypi.python.org/pypi/pysal',
         license='BSD',
         packages=find_packages(),
-        python_requires='>3.6',
+        python_requires='>=3.6',
         test_suite='nose.collector',
         tests_require=['nose'],
         keywords='spatial statistics',
