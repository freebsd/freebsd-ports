--- hdf/src/cszip.c.orig	Wed Mar 16 14:27:46 2005
+++ hdf/src/cszip.c	Wed Mar 16 14:27:49 2005
@@ -865,6 +865,7 @@
     compinfo_t *info;           /* special element information */
     comp_coder_szip_info_t *szip_info;    /* ptr to SZIP info */
 
+#ifdef H4_HAVE_LIBSZ
     if (SZ_encoder_enabled() == 0) 
 	HRETURN_ERROR(DFE_NOENCODER, FAIL);
     info = (compinfo_t *) access_rec->special_info;
@@ -881,6 +882,11 @@
         HRETURN_ERROR(DFE_CENCODE, FAIL);
 
     return (length);
+#else /* ifdef H4_HAVE_LIBSZ */
+
+    HRETURN_ERROR(DFE_CANTDECOMP, FAIL);
+
+#endif /* H4_HAVE_LIBSZ */
 }   /* HCPcszip_write() */
 
 /*--------------------------------------------------------------------------
