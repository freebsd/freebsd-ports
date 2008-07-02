--- TESTING/pdgssvx.c.orig	2008-06-18 22:10:35.000000000 -0500
+++ TESTING/pdgssvx.c	2008-06-18 22:11:10.000000000 -0500
@@ -1,6 +1,13 @@
 #include "pdsp_defs.h"
 #include "util.h"
 
+/* SuperLU compatibility */
+#define DN SLU_DN
+#define _D SLU_D
+#define GE SLU_GE
+#define NC SLU_NC
+#define NR SLU_NR
+
 void
 pdgssvx(int nprocs, pdgstrf_options_t *pdgstrf_options, SuperMatrix *A, 
 	int *perm_c, int *perm_r, equed_t *equed, double *R, double *C,
