--- plugin/oprobit.c.orig	Fri Feb 16 06:47:19 2007
+++ plugin/oprobit.c	Sat Apr 14 03:58:23 2007
@@ -665,6 +665,7 @@
     gretl_matrix *V = NULL;
     double *theta = NULL;
     int err;
+    op_container *OC;
 
     /* BFGS apparatus */
     int maxit = 1000;
@@ -679,7 +680,7 @@
 	opt &= ~OPT_R;
     }
 
-    op_container *OC = op_container_new(ci, Z, pmod, opt);
+    OC = op_container_new(ci, Z, pmod, opt);
     if (OC == NULL) {
 	return E_ALLOC;
     }
