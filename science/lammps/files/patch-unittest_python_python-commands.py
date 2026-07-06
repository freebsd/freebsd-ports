-- Use assertAlmostEqual with a reasonable precision for platform energy comparison.
-- The hardcoded PE value (-3.9848867644689534) was computed on a specific
-- platform and differs in the last few decimal places on FreeBSD due to
-- differences in math library FP evaluation order.

--- unittest/python/python-commands.py.orig	2026-06-07 21:48:32 UTC
+++ unittest/python/python-commands.py
@@ -557,7 +557,7 @@ create_atoms 1 single &
         self.assertEqual(self.lmp.eval("4+5"), 9.0)
         self.assertEqual(self.lmp.eval("v_one / 2.0"), 0.5)
         self.assertEqual(self.lmp.eval("count(all)"), 36.0)
-        self.assertEqual(self.lmp.eval("pe"), -3.9848867644689534)
+        self.assertAlmostEqual(self.lmp.eval("pe"), -3.9848867644689534, places=10)
 
     def test_get_thermo(self):
         self.lmp.command("units lj")
