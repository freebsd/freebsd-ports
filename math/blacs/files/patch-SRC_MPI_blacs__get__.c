--- SRC/MPI/blacs_get_.c.orig	2006-01-18 21:36:03 UTC
+++ SRC/MPI/blacs_get_.c
@@ -12,6 +12,8 @@ F_VOID_FUNC blacs_get_(int *ConTxt, int *what, int *va
 #else
    int comm;
 #endif
+   void BI_MPI_C_to_f77_trans_comm(MPI_Comm, int *);
+   void BI_MPI_F77_to_c_trans_comm(int F77comm, MPI_Comm *Ccomm);
    BLACSCONTEXT *ctxt;
 
    switch( Mpval(what) )
