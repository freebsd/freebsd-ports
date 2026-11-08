-- Make cbc_dist_dir() return the system LOCALBASE directory instead of a
-- bundled cbc_dist subdirectory. The other path helpers then automatically
-- resolve to the math/cbc binary, libraries and headers installed by FreeBSD.

--- src/__init__.py.orig	2026-08-17 02:08:17 UTC
+++ src/__init__.py
@@ -56,45 +56,11 @@ def cbc_dist_dir() -> str:
 
 
 def cbc_dist_dir() -> str:
-    pkg_dir        = os.path.abspath(os.path.dirname(__file__))
-    base_dir       = os.path.join(pkg_dir, "cbc_dist")
-    avx2_dir       = os.path.join(pkg_dir, "cbc_dist_avx2")
-    debug_dir      = os.path.join(pkg_dir, "cbc_dist_debug")
-    debug_avx2_dir = os.path.join(pkg_dir, "cbc_dist_debug_avx2")
+    """Return the system LOCALBASE directory where math/cbc is installed."""
+    chosen = "@LOCALBASE@"
 
-    override = os.environ.get("CBCBOX_BUILD", "").strip().lower()
-    if override == "avx2":
-        if not os.path.isdir(avx2_dir):
-            raise RuntimeError(
-                "CBCBOX_BUILD=avx2 requested but the AVX2 build is not "
-                "present in this installation (x86_64 Linux/macOS/Windows only)."
-            )
-        chosen = avx2_dir
-    elif override == "debug":
-        # On x86_64 the only debug variant shipped is debug+AVX2 (haswell).
-        # On other architectures the plain debug build is used.
-        if os.path.isdir(debug_avx2_dir):
-            chosen = debug_avx2_dir
-        elif os.path.isdir(debug_dir):
-            chosen = debug_dir
-        else:
-            raise RuntimeError(
-                "CBCBOX_BUILD=debug requested but no debug build is present "
-                "in this installation."
-            )
-    elif override == "generic":
-        chosen = base_dir
-    elif override:
-        raise ValueError(
-            f"Unknown CBCBOX_BUILD value {override!r}. "
-            "Use 'generic', 'avx2', or 'debug'."
-        )
-    else:
-        # Auto-select: prefer AVX2 when available and supported by the CPU.
-        chosen = avx2_dir if os.path.isdir(avx2_dir) and _has_avx2() else base_dir
-
     verbose = os.environ.get("CBCBOX_VERBOSE", "").strip() == "1"
-    if override or verbose:
+    if verbose:
         _print_build_info(chosen)
 
     return chosen
