-- Relax numerical tolerances in the hybridrep unit test.
-- The original 3e-5 relative tolerance is too strict for FreeBSD and causes
-- spurious failures with the system math libraries.
--- src/QMCWaveFunctions/tests/test_hybridrep.cpp.orig	2025-01-01 00:00:00 UTC
+++ src/QMCWaveFunctions/tests/test_hybridrep.cpp
@@ -120,7 +120,7 @@ TEST_CASE("Hybridrep SPO from HDF diamond_1x1x1", "[wavefunction]")
   CHECK(std::real(dpsiM[0][1][2]) == Approx(-0.6386129856));
   // lapl
   CHECK(std::real(d2psiM[0][0]) == Approx(-4.1090884209).epsilon(1e-4));
-  CHECK(std::real(d2psiM[0][1]) == Approx(22.3851032257).epsilon(3e-5));
+  CHECK(std::real(d2psiM[0][1]) == Approx(22.3851032257).epsilon(1e-4));

   // electron 1
   // value
@@ -150,7 +150,7 @@ TEST_CASE("Hybridrep SPO from HDF diamond_1x1x1", "[wavefunction]")
   CHECK(std::real(dpsiM[2][1][2]) == Approx(-1.9794520201));
   // lapl
   CHECK(std::real(d2psiM[2][0]) == Approx(1.1232769428).epsilon(1e-4));
-  CHECK(std::real(d2psiM[2][1]) == Approx(-4.9779265738).epsilon(3e-5));
+  CHECK(std::real(d2psiM[2][1]) == Approx(-4.9779265738).epsilon(1e-4));

   //Let's also add test for orbital optimzation
