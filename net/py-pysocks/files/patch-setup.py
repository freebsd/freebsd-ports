--- setup.py.orig	2019-05-11 09:18:35 UTC
+++ setup.py
@@ -19,7 +19,7 @@ setup(
     VERSION = re.compile(r'.*__version__ = "(.*?)"', re.S).match(f.read()).group(1)
 
 setup(
-    name="PySocks",
+    name="pysocks",
     version=VERSION,
     description="A Python SOCKS client module. See https://github.com/Anorov/PySocks for more information.",
     long_description=long_description,
@@ -32,12 +32,12 @@ setup(
     py_modules=["socks", "sockshandler"],
     install_requires=requirements,
     python_requires=">=2.7, !=3.0.*, !=3.1.*, !=3.2.*, !=3.3.*",
-    classifiers=(
+    classifiers=[
         "Programming Language :: Python :: 2",
         "Programming Language :: Python :: 2.7",
         "Programming Language :: Python :: 3",
         "Programming Language :: Python :: 3.4",
         "Programming Language :: Python :: 3.5",
         "Programming Language :: Python :: 3.6",
-    ),
+    ],
 )
