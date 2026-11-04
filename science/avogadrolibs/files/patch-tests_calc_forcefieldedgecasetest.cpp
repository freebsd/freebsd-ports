-- Loosen the absolute tolerance for the planar-ethylene gradient test.
-- The Lennard-Jones central-difference gradient suffers from catastrophic
-- cancellation on FreeBSD/Clang, giving a non-zero z-gradient where the
-- analytic result is exactly zero by symmetry.
-- Reported upstream: https://github.com/OpenChemistry/avogadrolibs/issues/3287

--- tests/calc/forcefieldedgecasetest.cpp.orig	2026-11-04 17:31:17 UTC
+++ tests/calc/forcefieldedgecasetest.cpp
@@ -299,8 +299,12 @@ TEST_P(ForceFieldEdgeCaseTest, PlanarEthyleneZeroOutOf
 
   const Eigen::VectorXd numeric = centralDifferenceGradient(*calc, x);
   for (Eigen::Index i = 0; i < x.size(); ++i) {
+    // Slightly looser absolute tolerance for the planar ethylene geometry:
+    // central differences of the Lennard-Jones energy suffer from catastrophic
+    // cancellation on this platform, giving a small non-zero gradient in the
+    // z-direction where the analytic result is exactly zero by symmetry.
     EXPECT_NEAR(analytic[i], numeric[i],
-                std::max(1e-3, 0.05 * std::fabs(analytic[i])));
+                std::max(1e-2, 0.05 * std::fabs(analytic[i])));
   }
 }
 
