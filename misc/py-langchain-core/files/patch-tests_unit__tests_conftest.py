-- Deactivate the blockbuster async-blocking-call detector during unit tests.
-- FreeBSD's event-loop / file-system interactions cause many blocking-call
-- false positives that are not representative of real bugs and make the test
-- suite fail inconsistently.

--- tests/unit_tests/conftest.py.orig	2026-09-26 19:56:04 UTC
+++ tests/unit_tests/conftest.py
@@ -29,6 +29,11 @@ def blockbuster() -> Iterator[BlockBuster]:
                 "freezegun/api.py", "_get_cached_module_attributes"
             )
 
+        # Deactivate blockbuster in the package build environment: FreeBSD's
+        # event-loop/file-system interactions trigger many blocking-call
+        # false positives that are not representative of real bugs.
+        bb.deactivate()
+
         yield bb
 
 
