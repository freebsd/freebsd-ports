Revert:		https://github.com/pyauth/python-pkcs11/commit/d45957fd94abfd01b47cbf6a5b96862cf542dfbb

--- setup.py.orig	2025-06-27 14:01:42 UTC
+++ setup.py
@@ -0,0 +1,26 @@
+# Add cython extension module to build configuration.
+#
+# See also: https://setuptools.pypa.io/en/latest/userguide/ext_modules.html
+
+import platform
+
+from setuptools import Extension, setup
+
+libraries = []
+
+# if compiling using MSVC, we need to link against user32 library
+if platform.system() == "Windows":
+    libraries.append("user32")
+
+
+setup(
+    ext_modules=[
+        Extension(
+            name="pkcs11._pkcs11",
+            sources=[
+                "pkcs11/_pkcs11.pyx",
+            ],
+            libraries=libraries,
+        ),
+    ],
+)
