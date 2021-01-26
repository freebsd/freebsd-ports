--- setup.py.orig	2020-11-06 14:25:11 UTC
+++ setup.py
@@ -27,10 +27,7 @@ VERSION = '3.1.0'
 # Minimum supported versions of Numpy & Cython depend on the Python version
 NUMPY_MIN_VERSIONS = [
     # Numpy    Python
-    ('1.12',   "=='3.6'"),
-    ('1.14.5', "=='3.7'"),
-    ('1.17.5', "=='3.8'"),
-    ('1.19.3', ">='3.9'"),
+    ('1.14.5', ">='3.6'"),
 ]
 
 # these are required to use h5py
@@ -49,7 +46,7 @@ SETUP_REQUIRES = [
     f"Cython >=0.29; python_version<'3.8'",
     f"Cython >=0.29.14; python_version>='3.8'",
 ] + [
-    f"numpy =={np_min}; python_version{py_condition}"
+    f"numpy >={np_min}; python_version{py_condition}"
     for np_min, py_condition in NUMPY_MIN_VERSIONS
 ]
 
