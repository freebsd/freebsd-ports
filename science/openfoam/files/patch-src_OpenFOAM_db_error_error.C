--- ./src/OpenFOAM/db/error/error.C.orig	Fri Feb 24 17:56:39 2006
+++ ./src/OpenFOAM/db/error/error.C	Fri Mar 31 14:06:02 2006
@@ -38,7 +38,7 @@
 #if defined(__GNUC__)
 #include "IStringStream.H"
 #include <execinfo.h>
-#include <demangle.h>
+#include <libiberty/demangle.h>
 #endif
 
 // * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //
