-- Fix build with BOUT++ >= 5.0: Laplacian::create() now returns std::unique_ptr<Laplacian>
-- instead of a raw pointer, requiring member variable type change.
-- Upstream issue: https://github.com/boutproject/merging-filaments/issues/6

--- merging-flux.cxx.orig	2026-09-27 09:53:07 UTC
+++ merging-flux.cxx
@@ -242,8 +242,8 @@ class MergingFlux : public PhysicsModel { (private)
 
   Field2D B0;  // Magnetic field [T]
 
-  Laplacian *phiSolver; // Solver for potential phi from vorticity
-  Laplacian *psiSolver; // Solver for psi from current Jpar
+  std::unique_ptr<Laplacian> phiSolver; // Solver for potential phi from vorticity
+  std::unique_ptr<Laplacian> psiSolver; // Solver for psi from current Jpar
 
   BoutReal resistivity;
   BoutReal viscosity;
