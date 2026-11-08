-- Skip building the arrow-rs-wrapper Rust library.
-- It requires vendoring the arrow crate ecosystem which is not currently
-- included in the FreeBSD port's cargo-crates. The resulting shared library
-- is only needed for parquet run-history reading and is not exercised by
-- the test suite.

--- hatch_build.py.orig	2026-09-06 07:00:00 UTC
+++ hatch_build.py
@@ -121,6 +121,10 @@
     def _build_arrow_rs_wrapper(self) -> list[str]:
         """Build the arrow-rs-wrapper dynamic library."""
+
+        # Skip building arrow-rs-wrapper: the arrow crate ecosystem is not
+        # vendored in this port, and the library is not required for tests.
+        return []
         plat = self._target_platform()

         if plat.goos == "windows":
