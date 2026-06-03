diff --git a/www/web2ldap/files/patch-setup.py b/www/web2ldap/files/patch-setup.py
new file mode 100644
index 000000000..7c7970eb2
--- /dev/null
+++ b/www/web2ldap/files/patch-setup.py
@@ -0,0 +1,11 @@
+--- setup.py.orig	2026-04-13 10:32:57 UTC
++++ setup.py
+@@ -53,7 +53,7 @@ setup(
+     packages=find_packages(exclude=['tests']),
+     package_dir={'': '.'},
+     test_suite='tests',
+-    python_requires='>=3.6.*',
++    python_requires='>=3.6',
+     include_package_data=True,
+     data_files=DATA_FILES,
+     install_requires=[
