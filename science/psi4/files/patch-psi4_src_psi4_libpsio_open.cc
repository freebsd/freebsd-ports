--- psi4/src/psi4/libpsio/open.cc.orig	2022-11-22 21:26:37 UTC
+++ psi4/src/psi4/libpsio/open.cc
@@ -41,6 +41,11 @@
 #include "psi4/libpsio/psio.h"
 #include "psi4/libpsio/psio.hpp"
 #include "psi4/psi4-dec.h"
+
+#if defined(__FreeBSD__)
+#include <sys/stat.h>
+#endif
+
 namespace psi {
 
 void PSIO::open(size_t unit, int status) {
