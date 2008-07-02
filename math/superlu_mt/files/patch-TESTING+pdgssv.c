--- TESTING/pdgssv.c.orig	2008-06-18 22:09:01.000000000 -0500
+++ TESTING/pdgssv.c	2008-06-18 22:10:18.000000000 -0500
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
 pdgssv(int nprocs, SuperMatrix *A, int *perm_c, int *perm_r, 
        SuperMatrix *L, SuperMatrix *U, SuperMatrix *B, int *info )
