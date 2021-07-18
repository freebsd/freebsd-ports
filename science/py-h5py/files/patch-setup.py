--- setup.py.orig	2021-03-05 10:02:07 UTC
+++ setup.py
@@ -27,9 +27,7 @@ VERSION = '3.2.1'
 # Minimum supported versions of Numpy & Cython depend on the Python version
 NUMPY_MIN_VERSIONS = [
     # Numpy    Python
-    ('1.14.5', "=='3.7'"),
-    ('1.17.5', "=='3.8'"),
-    ('1.19.3', ">='3.9'"),
+    ('1.14.5', ">='3.7'"),
 ]
 
 # these are required to use h5py
@@ -49,7 +47,7 @@ SETUP_REQUIRES = [
     "Cython >=0.29.14; python_version=='3.8'",
     "Cython >=0.29.15; python_version>='3.9'",
 ] + [
-    f"numpy =={np_min}; python_version{py_condition}"
+    f"numpy >={np_min}; python_version{py_condition}"
     for np_min, py_condition in NUMPY_MIN_VERSIONS
 ]
 
