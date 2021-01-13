--- xdrawchem/molecule.h.orig	2017-01-09 12:25:32 UTC
+++ xdrawchem/molecule.h
@@ -3,6 +3,10 @@
 #ifndef MOLECULE_H
 #define MOLECULE_H
 
+#include <openbabel/atom.h>
+#include <openbabel/bond.h>
+#include <openbabel/elements.h>
+#include <openbabel/math/vector3.h>
 #include <openbabel/mol.h>
 #include <openbabel/obconversion.h>
 
