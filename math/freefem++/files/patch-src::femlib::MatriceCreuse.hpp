--- ./src/femlib/MatriceCreuse.hpp.orig	Mon Apr 16 15:29:19 2007
+++ ./src/femlib/MatriceCreuse.hpp	Wed Apr 18 22:10:17 2007
@@ -10,15 +10,19 @@
 #include <umfpack.h>
 #else
 #ifdef HAVE_UMFPACK_UMFPACK_H
-#include <umfpack/umfpack.h>
+#include <UMFPACK/umfpack.h>
 #else
 #ifdef HAVE_BIG_UMFPACK_UMFPACK_H
 #include <UMFPACK/umfpack.h>
 #else
+#ifdef HAVE_UFSPARSE_UMFPACK_H
+#include <ufsparse/umfpack.h>
+#else
 
   // Defaults to a local version of the UMFPACK headers
 #include "../../download/include/umfpack.h"
 
+#endif // HAVE_UFSPARSE_UMFPACK_H
 #endif // HAVE_BIG_UMFPACK_UMFPACK_H
 #endif // HAVE_UMFPACK_UMFPACK_H
 #endif // HAVE_UMFPACK_H
