https://github.com/lammps/lammps/issues/2062

--- lib/atc/Function.cpp.orig	2020-05-03 03:21:56 UTC
+++ lib/atc/Function.cpp
@@ -1,5 +1,5 @@
 #ifndef _WIN32
-#include <alloca.h>
+#include <stdlib.h>
 #endif
 #include "Function.h"
 #include "ATC_Error.h"
