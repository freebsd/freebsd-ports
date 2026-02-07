--- SRC/MPI/blacs_pinfo_.c.orig	1998-03-13 20:16:27 UTC
+++ SRC/MPI/blacs_pinfo_.c
@@ -1,5 +1,8 @@
 #include "Bdef.h"
 
+void bi_f77_init_(void);
+void bi_f77_get_constants_(int*, int*, int*);
+
 #if (INTFACE == C_CALL)
 void Cblacs_pinfo(int *mypnum, int *nprocs)
 #else
