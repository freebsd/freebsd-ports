--- Makefile.PL.orig	2010-03-11 02:51:47.000000000 -0500
+++ Makefile.PL	2010-03-11 02:52:00.000000000 -0500
@@ -17,34 +17,6 @@
     Text::Balanced      1.89
 ));
 
-bundle(qw(
-    Chemistry::File::VRML           0.10
-    Chemistry::3DBuilder            0.10
-    Chemistry::Mol                  0.35
-    Chemistry::Mok                  0.25
-    Chemistry::File::SMILES         0.44
-    Chemistry::File::SMARTS         0.22
-    Chemistry::File::PDB            0.21
-    Chemistry::Pattern              0.26
-    Chemistry::MidasPattern         0.11
-    Chemistry::File::MDLMol         0.20
-    Chemistry::InternalCoords       0.18
-    Chemistry::MacroMol             0.06
-    Chemistry::Ring                 0.18
-    Chemistry::Canonicalize         0.10
-    Chemistry::Bond::Find           0.21
-    Chemistry::File::SLN            0.10
-    Chemistry::FormulaPattern       0.10
-    Chemistry::File::Mopac          0.15
-    Chemistry::File::XYZ            0.11
-    Chemistry::Isotope              0.11
-    Chemistry::Reaction             0.02
-    Math::VectorReal                1.00
-    Statistics::Regression          0.15
-    Parse::Yapp::Driver             1.05
-
-));
-
 check_nmake();
 
 &WriteAll();
