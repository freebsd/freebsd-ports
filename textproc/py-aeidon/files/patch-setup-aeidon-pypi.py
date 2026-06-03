--- setup-aeidon-pypi.py.orig	2026-04-13 19:25:36 UTC
+++ setup-aeidon-pypi.py
@@ -8,22 +8,22 @@ please use the main setup.py as explained in README.ae
 please use the main setup.py as explained in README.aeidon.md.
 """
 
-import shutil
+#import shutil
 
-from setup import get_aeidon_version
+#from setup import get_aeidon_version
 from setuptools import find_packages
 from setuptools import setup
 
 # Copy data files to the aeidon package, so they can be included.
-shutil.copytree("data/headers", "aeidon/data/headers")
-shutil.copytree("data/patterns", "aeidon/data/patterns")
+#shutil.copytree("data/headers", "aeidon/data/headers")
+#shutil.copytree("data/patterns", "aeidon/data/patterns")
 
-with open("README.aeidon.md", "r") as f:
+with open("README.md", "r") as f:
     long_description = f.read()
 
 setup(
     name="aeidon",
-    version=get_aeidon_version(),
+    version="%%PORTVERSION%%",
     author="Osmo Salomaa",
     author_email="otsaloma@iki.fi",
     description="Reading, writing and manipulating text-based subtitle files",
@@ -32,9 +32,10 @@ setup(
     url="https://github.com/otsaloma/gaupol",
     license="GPL",
     packages=find_packages(exclude=["gaupol*", "*.test"]),
-    package_data={"aeidon": ["data/*/*"]},
+    package_data={"aeidon": ["aeidon/data/*/*"]},
+    include_package_data=True,
     python_requires=">=3.5.0",
     install_requires=["charset-normalizer>2.0"],
 )
 
-shutil.rmtree("aeidon/data")
+#shutil.rmtree("aeidon/data")
