-- Relax floating-point precision in test_task_energy_with_live_update_interference
-- to account for tiny GPU energy contributions on FreeBSD.

--- tests/test_emissions_tracker.py.orig	2026-10-26 11:41:25.074074000 -0700
+++ tests/test_emissions_tracker.py	2026-10-26 11:41:16.839437000 -0700
@@ -1149,7 +1149,7 @@
         self.assertAlmostEqual(
             task_data.energy_consumed,
             expected_total_energy,
-            places=7,
+            places=6,
             msg="Total energy consumed does not match sum of components",
         )
 
