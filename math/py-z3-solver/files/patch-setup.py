--- setup.py.orig	2018-07-21 19:34:29 UTC
+++ setup.py
@@ -161,9 +161,5 @@ setup(
     keywords=['z3', 'smt', 'sat', 'prover', 'theorem'],
     packages=['z3'],
     include_package_data=True,
-    package_data={
-        'z3': [os.path.join('lib', '*'), os.path.join('include', '*.h'), os.path.join('include', 'c++', '*.h')]
-    },
-    data_files=[('bin',[os.path.join('bin',EXECUTABLE_FILE)])],
     cmdclass={'build': build, 'develop': develop, 'sdist': sdist, 'bdist_egg': bdist_egg},
 )
