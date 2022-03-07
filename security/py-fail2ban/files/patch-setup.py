--- setup.py.orig	2020-11-23 20:43:03 UTC
+++ setup.py
@@ -39,14 +39,7 @@ from distutils.command.build_scripts import build_scri
 if setuptools is None:
 	from distutils.command.install import install
 	from distutils.command.install_scripts import install_scripts
-try:
-	# python 3.x
-	from distutils.command.build_py import build_py_2to3
-	from distutils.command.build_scripts import build_scripts_2to3
-	_2to3 = True
-except ImportError:
-	# python 2.x
-	_2to3 = False
+_2to3 = False
 
 import os
 from os.path import isfile, join, isdir, realpath
@@ -186,7 +179,6 @@ commands.'''
 if setuptools:
 	setup_extra = {
 		'test_suite': "fail2ban.tests.utils.gatherTests",
-		'use_2to3': True,
 	}
 else:
 	setup_extra = {}
