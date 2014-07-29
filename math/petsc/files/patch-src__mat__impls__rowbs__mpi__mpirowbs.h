--- src/mat/impls/rowbs/mpi/mpirowbs.h.orig	Sat Oct  2 09:13:29 2004
+++ src/mat/impls/rowbs/mpi/mpirowbs.h	Tue Oct  5 21:58:07 2004
@@ -5,8 +5,8 @@
 #include "src/mat/matimpl.h"
 
 EXTERN_C_BEGIN
-#include "BSsparse.h"
-#include "BSprivate.h"
+#include <BSsparse.h>
+#include <BSprivate.h>
 EXTERN_C_END
 
 /*
