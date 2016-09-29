--- include/ac/mpi.h.orig	2015-10-30 05:05:33 UTC
+++ include/ac/mpi.h
@@ -35,7 +35,7 @@
 #ifdef HAVE_MPI___H
 #include <mpi++.h>
 #elif defined HAVE_MPICXX_H
-#include <mpicxx.h>
+#include <mpi.h>
 #endif /* ! HAVE_MPI___H && ! HAVE_MPICXX_H */
 
 #endif /* MPI_H */
