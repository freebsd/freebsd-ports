-- Make the test fixture report a single "system" CBC variant that points at
-- the math/cbc binary, since this port does not bundle cbc_dist* builds.

--- tests/conftest.py.orig	2026-09-08 23:28:23 UTC
+++ tests/conftest.py
@@ -23,19 +23,12 @@ def _get_build_variants():
 
 
 def _get_build_variants():
-    """Return [(variant_name, binary_path), ...] for every available CBC build.
+    """Return a single system CBC build variant.
 
-    Always includes 'generic'; adds 'avx2' when cbc_dist_avx2/ is present
-    (x86_64 Linux/macOS/Windows wheels only).
+    The FreeBSD port uses the system math/cbc binary instead of bundled
+    cbc_dist* subdirectories.
     """
-    pkg_dir = os.path.abspath(os.path.dirname(cbcbox.__file__))
-    cbc_exe = "cbc.exe" if os.name == "nt" else "cbc"
-    variants = []
-    for name, subdir in [("generic", "cbc_dist"), ("avx2", "cbc_dist_avx2")]:
-        binary = os.path.join(pkg_dir, subdir, "bin", cbc_exe)
-        if os.path.isfile(binary):
-            variants.append((name, binary))
-    return variants
+    return [("system", cbcbox.cbc_bin_path())]
 
 
 def pytest_configure(config):
