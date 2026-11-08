-- (1) not install tests
-- (2) remove questionable ensure_python() that can cause problems with higher Python versions

--- setup.py.orig	2021-01-25 10:40:44 UTC
+++ setup.py
@@ -23,9 +22,6 @@ name = 'ipygany'
 
 HERE = path.dirname(path.abspath(__file__))
 
-# Ensure a valid python version
-ensure_python('>=3.6')
-
 # Get our version
 version = get_version(path.join(name, '_version.py'))
 
@@ -71,7 +67,7 @@ setup_args = dict(
     version=version,
     scripts=glob(path.join('scripts', '*')),
     cmdclass=cmdclass,
-    packages=find_packages(),
+    packages=find_packages(exclude=["tests", "tests.*"]),
     author='Martin Renou',
     author_email='martin.renou@gmail.com',
     url='https://github.com/martinRenou/ipygany',
