--- ./src/femlib/MatriceCreuse.hpp.orig	Fri Jun 25 10:56:36 2004
+++ ./src/femlib/MatriceCreuse.hpp	Thu Jul  8 00:19:27 2004
@@ -10,7 +10,7 @@
 #include <umfpack.h>
 #else
 #ifdef HAVE_UMFPACK_UMFPACK_H
-#include <umfpack/umfpack.h>
+#include <UMFPACK/umfpack.h>
 #else
 
   // Defaults to a local version of the UMFPACK headers
