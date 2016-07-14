--- setup.py.orig	2016-07-13 11:25:00 UTC
+++ setup.py
@@ -10,12 +10,6 @@ if version < '1.0.0':
     print("Python 1 is not supported...")
     sys.exit(1)
 
-here = path.abspath(path.dirname(__file__))
-with open(path.join(here, 'README.rst'), "rb") as f:
-    longd = f.read().decode("utf-8")
-print(longd)
-
-
 setup(
     name='socli',
     packages=["socli"],
@@ -29,5 +23,5 @@ setup(
     author='Gautam krishna R',
     author_email='r.gautamkrishna@gmail.com',
     description='Stack overflow commnand line interface. SoCLI allows you to search and browse stack overfow from the terminal.',
-    long_description=longd
+    long_description=long
     )
