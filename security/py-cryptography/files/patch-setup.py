--- setup.py.orig	2021-03-25 17:19:57 UTC
+++ setup.py
@@ -10,23 +10,7 @@ import sys
 
 from setuptools import find_packages, setup
 
-try:
-    from setuptools_rust import RustExtension
-except ImportError:
-    print(
-        """
-        =============================DEBUG ASSISTANCE==========================
-        If you are seeing an error here please try the following to
-        successfully install cryptography:
 
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
 
@@ -41,9 +25,8 @@ with open(os.path.join(src_dir, "cryptography", "__abo
 
 # `install_requirements` and `setup_requirements` must be kept in sync with
 # `pyproject.toml`
-setuptools_rust = "setuptools-rust>=0.11.4"
 install_requirements = ["cffi>=1.12"]
-setup_requirements = install_requirements + [setuptools_rust]
+setup_requirements = install_requirements
 
 if os.environ.get("CRYPTOGRAPHY_DONT_BUILD_RUST"):
     rust_extensions = []
@@ -129,9 +112,6 @@ try:
                 "twine >= 1.12.0",
                 "sphinxcontrib-spelling >= 4.0.1",
             ],
-            "sdist": [
-                setuptools_rust,
-            ],
             "pep8test": [
                 "black",
                 "flake8",
@@ -149,7 +129,6 @@ try:
             "src/_cffi_src/build_openssl.py:ffi",
             "src/_cffi_src/build_padding.py:ffi",
         ],
-        rust_extensions=rust_extensions,
     )
 except:  # noqa: E722
     # Note: This is a bare exception that re-raises so that we don't interfere
