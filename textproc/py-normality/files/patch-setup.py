Really exclude "tests" directory to be installed into
${PYTHONPREFIX_SITELIBDIR}

--- setup.py.orig	2020-06-21 09:47:38 UTC
+++ setup.py
@@ -24,7 +24,7 @@ setup(
     url='http://github.com/pudo/normality',
     license='MIT',
     package_data={'banal': ['py.typed']},
-    packages=find_packages(exclude=['ez_setup', 'examples', 'test']),
+    packages=find_packages(exclude=['ez_setup', 'examples', 'tests']),
     namespace_packages=[],
     include_package_data=True,
     zip_safe=False,
