--- setup.py.orig	2015-07-31 10:13:11 UTC
+++ setup.py
@@ -3,7 +3,7 @@ from setuptools import setup, find_packa
 setup(
 	name='bench',
 	version='0.92',
-	py_modules=find_packages(),
+	packages=find_packages(),
 	include_package_data=True,
 	url='https://github.com/frappe/bench',
 	author='Web Notes Technologies Pvt. Ltd.',
@@ -15,7 +15,7 @@ setup(
 		'requests',
 		'honcho',
 		'semantic_version',
-		'GitPython==0.3.2.RC1'
+		'GitPython>=0.3.2.RC1'
     ],
 	entry_points='''
 [console_scripts]
