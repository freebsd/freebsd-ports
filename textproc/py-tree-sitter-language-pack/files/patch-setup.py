--- setup.py.orig	2025-09-24 08:43:32 UTC
+++ setup.py
@@ -4,7 +4,7 @@ from setuptools import Extension, find_packages, setup
 from platform import system
 
 from setuptools import Extension, find_packages, setup
-from setuptools.command.bdist_wheel import bdist_wheel
+#from setuptools.command.bdist_wheel import bdist_wheel
 from setuptools.command.build_ext import build_ext
 
 MIN_PYTHON_VERSION = 39
@@ -99,19 +99,19 @@ class BuildExt(build_ext):
         super().build_extension(ext)
 
 
-class BdistWheel(bdist_wheel):
-    """Custom bdist_wheel command to handle Python 3.9+ ABI tag."""
+#class BdistWheel(bdist_wheel):
+#    """Custom bdist_wheel command to handle Python 3.9+ ABI tag."""
+#
+#    def get_tag(self) -> tuple[str, str, str]:
+#        """Get the tag for the wheel."""
+#        python, abi, platform = super().get_tag()
+#        platform = platform.replace("linux", "manylinux2014")
+#        if python.startswith("cp") and int(python[2:]) >= MIN_PYTHON_VERSION:
+#            # Support all Python versions >= 3.9 using abi3
+#            return "cp39", "abi3", platform
+#        return python, abi, platform
 
-    def get_tag(self) -> tuple[str, str, str]:
-        """Get the tag for the wheel."""
-        python, abi, platform = super().get_tag()
-        platform = platform.replace("linux", "manylinux2014")
-        if python.startswith("cp") and int(python[2:]) >= MIN_PYTHON_VERSION:
-            # Support all Python versions >= 3.9 using abi3
-            return "cp39", "abi3", platform
-        return python, abi, platform
 
-
 setup(
     packages=find_packages(include=["tree_sitter_language_pack", "tree_sitter_language_pack.bindings"]),
     package_data={"tree_sitter_language_pack": ["py.typed"]},
@@ -120,7 +120,6 @@ setup(
     include_package_data=True,
     cmdclass={
         "build_ext": BuildExt,
-        "bdist_wheel": BdistWheel,
     },
     options={"build_ext": {"inplace": True}},
 )
