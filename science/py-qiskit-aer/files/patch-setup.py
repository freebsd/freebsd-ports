--- setup.py.orig	2022-08-08 17:21:16 UTC
+++ setup.py
@@ -27,8 +27,9 @@ PACKAGE_NAME = os.getenv('QISKIT_AER_PACKAGE_NAME', 'q
 _DISABLE_CONAN = strtobool(os.getenv("DISABLE_CONAN", "OFF"))
 _DISABLE_DEPENDENCY_INSTALL = strtobool(os.getenv("DISABLE_DEPENDENCY_INSTALL", "OFF"))
 
+_DISABLE_CONAN = True
+_DISABLE_DEPENDENCY_INSTALL = True
 
-
 def install_needed_req(import_name, package_name=None, min_version=None, max_version=None):
     if package_name is None:
         package_name = import_name
@@ -72,7 +73,6 @@ common_requirements = [
 
 setup_requirements = common_requirements + [
     'scikit-build>=0.11.0',
-    'cmake!=3.17,!=3.17.0',
     'pybind11>=2.6',
 ]
 
