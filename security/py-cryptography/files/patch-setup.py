--- setup.py.orig	2022-09-07 12:20:58 UTC
+++ setup.py
@@ -13,23 +13,6 @@ import sys
 
 from setuptools import setup
 
-try:
-    from setuptools_rust import RustExtension
-except ImportError:
-    print(
-        """
-        =============================DEBUG ASSISTANCE==========================
-        If you are seeing an error here please try the following to
-        successfully install cryptography:
-
-        Upgrade to the latest pip and try again. This will fix errors for most
-        users. See: https://pip.pypa.io/en/stable/installing/#upgrading-pip
-        =============================DEBUG ASSISTANCE==========================
-        """
-    )
-    raise
-
-
 base_dir = os.path.dirname(__file__)
 src_dir = os.path.join(base_dir, "src")
 
@@ -43,20 +26,6 @@ try:
         cffi_modules=[
             "src/_cffi_src/build_openssl.py:ffi",
         ],
-        rust_extensions=[
-            RustExtension(
-                "cryptography.hazmat.bindings._rust",
-                "src/rust/Cargo.toml",
-                py_limited_api=True,
-                # Enable abi3 mode if we're not using PyPy.
-                features=(
-                    []
-                    if platform.python_implementation() == "PyPy"
-                    else ["pyo3/abi3-py36"]
-                ),
-                rust_version=">=1.48.0",
-            )
-        ],
     )
 except:  # noqa: E722
     # Note: This is a bare exception that re-raises so that we don't interfere
@@ -86,7 +55,7 @@ except:  # noqa: E722
     )
     print(f"    Python: {'.'.join(str(v) for v in sys.version_info[:3])}")
     print(f"    platform: {platform.platform()}")
-    for dist in ["pip", "setuptools", "setuptools_rust"]:
+    for dist in ["pip", "setuptools"]:
         try:
             version = pkg_resources.get_distribution(dist).version
         except pkg_resources.DistributionNotFound:
