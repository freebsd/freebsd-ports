See https://github.com/iocage/iocage/issues/1043
--- setup.py.orig	2019-01-25 21:32:55 UTC
+++ setup.py
@@ -43,26 +43,26 @@ if sys.version_info < (3, 6):
 
 VERSION = '1.1'
 
-setup(
-    name='iocage_lib',
-    version=VERSION,
-    description='A jail manager that uses ZFS.',
-    author='iocage Contributors',
-    author_email='https://groups.google.com/forum/#!forum/iocage',
-    url='https://github.com/iocage/iocage',
-    packages=find_packages(),
-    include_package_data=True,
-    install_requires=[
-        'dulwich>=0.18.6',
-        'netifaces>=0.10.8',
-        'dnspython>=1.15.0',
-        'libzfs'
-    ],
-    setup_requires=['pytest-runner'],
-    entry_points={'console_scripts': ['iocage = iocage_lib:cli']},
-    data_files=_data,
-    tests_require=['pytest', 'pytest-cov', 'pytest-pep8']
-)
+#setup(
+#    name='iocage_lib',
+#    version=VERSION,
+#    description='A jail manager that uses ZFS.',
+#    author='iocage Contributors',
+#    author_email='https://groups.google.com/forum/#!forum/iocage',
+#    url='https://github.com/iocage/iocage',
+#    packages=find_packages(),
+#    include_package_data=True,
+#    install_requires=[
+#        'dulwich>=0.18.6',
+#        'netifaces>=0.10.8',
+#        'dnspython>=1.15.0',
+#        'libzfs'
+#    ],
+#    setup_requires=['pytest-runner'],
+#    entry_points={'console_scripts': ['iocage = iocage_lib:cli']},
+#    data_files=_data,
+#    tests_require=['pytest', 'pytest-cov', 'pytest-pep8']
+#)
 
 setup(
     name='iocage_cli',
