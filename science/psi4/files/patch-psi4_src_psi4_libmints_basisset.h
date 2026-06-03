--- psi4/src/psi4/libmints/basisset.h.orig	2026-04-20 18:11:32 UTC
+++ psi4/src/psi4/libmints/basisset.h
@@ -29,9 +29,7 @@
 #ifndef _psi_src_lib_libmints_basisset_h_
 #define _psi_src_lib_libmints_basisset_h_
 
-#ifdef _MSC_VER
 #include <libint2/shell.h>
-#endif
 #include "gshell.h"
 
 #include "psi4/pragma.h"
