--- xdrawchem/ioiface.h.orig	2017-01-09 12:25:32 UTC
+++ xdrawchem/ioiface.h
@@ -20,6 +20,9 @@
 
 #include "chemdata.h"
 
+#include <openbabel/atom.h>
+#include <openbabel/bond.h>
+#include <openbabel/math/vector3.h>
 #include <openbabel/mol.h>
 
 using namespace OpenBabel;
