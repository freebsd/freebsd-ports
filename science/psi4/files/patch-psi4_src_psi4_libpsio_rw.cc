- workaround for https://github.com/psi4/psi4/issues/2810

--- psi4/src/psi4/libpsio/rw.cc.orig	2022-12-01 20:44:27 UTC
+++ psi4/src/psi4/libpsio/rw.cc
@@ -32,6 +32,7 @@
  */
 
 #include <cstdio>
+#include <cerrno>
 #include "psi4/libpsio/psio.h"
 #include "psi4/libpsio/psio.hpp"
 #include "psi4/psi4-dec.h"
