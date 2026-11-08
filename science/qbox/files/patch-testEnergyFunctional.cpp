-- Rename s.wf.init() to s.wf.init_coeffs() in testEnergyFunctional.cpp.
-- The Wavefunction::init() method was removed/renamed in qbox 1.79.0, causing
-- a compile error. Use the replacement init_coeffs() method.
-- See https://github.com/qboxcode/qbox-public/issues/12
--- testEnergyFunctional.cpp.orig	2026-09-06 07:09:23 UTC
+++ testEnergyFunctional.cpp
@@ -109,7 +109,7 @@ int main(int argc, char **argv)
   s.ctrl.ecuts = 0.0;
   if ( MPIdata::onpe0() )
     cout << "s.wf.init()" << endl;
-  s.wf.init();
+  s.wf.init_coeffs();
   s.wf.gram();
   tm.reset();
   tm.start();
