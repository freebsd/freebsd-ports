-- Use EXPECT_NEAR with a reasonable tolerance for platform energy comparison.
-- The hardcoded PE value (-3.9848867644689534) was computed on a specific
-- platform and differs in the last few ULPs on FreeBSD due to differences
-- in math library FP evaluation order.

--- unittest/c-library/test_library_objects.cpp.orig	2026-06-07 21:48:32 UTC
+++ unittest/c-library/test_library_objects.cpp
@@ -261,6 +261,6 @@ TEST_F(LibraryObjects, eval)
     EXPECT_EQ(lammps_has_error(lmp), 0);
     EXPECT_DOUBLE_EQ(lammps_eval(lmp, "count(all)"), 36.0);
     EXPECT_EQ(lammps_has_error(lmp), 0);
-    EXPECT_DOUBLE_EQ(lammps_eval(lmp, "pe"), -3.9848867644689534);
+    EXPECT_NEAR(lammps_eval(lmp, "pe"), -3.9848867644689534, 1.0e-10);
     EXPECT_EQ(lammps_has_error(lmp), 0);
 }
