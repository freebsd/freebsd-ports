--- setup-aeidon.py.orig	2020-12-30 21:35:12 UTC
+++ setup-aeidon.py
@@ -2,30 +2,30 @@
 
 """setuptools/wheel/PyPI version of the aeidon package."""
 
-import shutil
+#import shutil
 
-from setup import get_aeidon_version
 from setuptools import find_packages
 from setuptools import setup
 
 # Copy data files to the aeidon package, so they can be included.
-shutil.copytree("data/headers", "aeidon/data/headers")
-shutil.copytree("data/patterns", "aeidon/data/patterns")
+#shutil.copytree("data/headers", "aeidon/data/headers")
+#shutil.copytree("data/patterns", "aeidon/data/patterns")
 
 setup(
     name="aeidon",
-    version=get_aeidon_version(),
+    version="%%PORTVERSION%%",
     author="Osmo Salomaa",
     author_email="otsaloma@iki.fi",
     description="Reading, writing and manipulating text-based subtitle files",
-    long_description=open("README.aeidon.md", "r").read(),
+    long_description=open("README.md", "r").read(),
     long_description_content_type="text/markdown",
     url="https://github.com/otsaloma/gaupol",
     license="GPL",
     packages=find_packages(exclude=["gaupol*", "*.test"]),
-    package_data={"aeidon": ["data/*/*"]},
+    package_data={"aeidon": ["aeidon/data/*/*"]},
+    include_package_data=True,
     python_requires=">=3.2.0",
     install_requires=["chardet>=2.2.1"],
 )
 
-shutil.rmtree("aeidon/data")
+#shutil.rmtree("aeidon/data")
