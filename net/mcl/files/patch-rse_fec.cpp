--- src/common/rse_fec.cpp.orig	2007-08-03 13:59:09.000000000 +0200
+++ src/common/rse_fec.cpp	2007-08-03 14:00:41.000000000 +0200
@@ -679,7 +679,7 @@
     struct fec_parms *p = (struct fec_parms *)p_vp;	/* VR */
 #endif /* CPLUSPLUS_COMPATIBLE */
     if (p==NULL ||
-       p->magic != ( ( (FEC_MAGIC ^ p->k) ^ p->n) ^ (int)(p->enc_matrix)) ) {
+       p->magic != ( ( (FEC_MAGIC ^ p->k) ^ p->n) ^ (intptr_t)(p->enc_matrix)) ) {
 	PRINT_ERR((mcl_stderr, "bad parameters to fec_free\n"))
 	return ;
     }
@@ -715,7 +715,7 @@
     retval->k = k ;
     retval->n = n ;
     retval->enc_matrix = NEW_GF_MATRIX(n, k);
-    retval->magic = ( ( FEC_MAGIC ^ k) ^ n) ^ (int)(retval->enc_matrix) ;
+    retval->magic = ( ( FEC_MAGIC ^ k) ^ n) ^ (intptr_t)(retval->enc_matrix) ;
     tmp_m = NEW_GF_MATRIX(n, k);
     /*
      * fill the matrix with powers of field elements, starting from 0.
