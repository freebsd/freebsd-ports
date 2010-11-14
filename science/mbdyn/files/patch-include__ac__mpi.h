--- ./include/ac/mpi.h.orig	2009-01-04 19:04:54.000000000 +0100
+++ ./include/ac/mpi.h	2010-10-31 22:31:57.000000000 +0100
@@ -35,7 +35,7 @@
 #ifdef HAVE_MPI___H
 #include <mpi++.h>
 #elif defined HAVE_MPICXX_H
-#include <mpicxx.h>
+#include <mpi.h>
 #endif /* ! HAVE_MPI___H && ! HAVE_MPICXX_H */
 
 #endif /* MPI_H */
