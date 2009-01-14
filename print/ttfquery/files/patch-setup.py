--- setup.py.orig	2008-01-02 11:51:03.000000000 +0900
+++ setup.py	2008-09-11 12:22:49.000000000 +0900
@@ -6,7 +6,7 @@
 to install the package from the source archive.
 """
 import sys,os, string
-from setuptools import setup
+from distutils.core import setup
 from sys import hexversion
 
 if __name__ == "__main__":
@@ -59,14 +59,6 @@
 		author_email = "mcfletch@users.sourceforge.net",
 		url = "http://ttfquery.sourceforge.net/",
 		license = "BSD-style, see license.txt for details",
-		include_package_data = True,
-
-		zip_safe=True,
-		install_requires = ['FontTools-numpy'],
-		dependency_links = [
-			# TTFQuery/FontTools-numpy
-			"https://sourceforge.net/project/showfiles.php?group_id=84080",
-		],
 		
 
 		package_dir = {
