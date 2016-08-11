--- _librsyncmodule.c.orig	2009-03-16 14:36:21 UTC
+++ _librsyncmodule.c
@@ -59,8 +59,13 @@ _librsync_new_sigmaker(PyObject* self, P
   if (sm == NULL) return NULL;
   sm->x_attr = NULL;
 
+#ifdef RS_DEFAULT_STRONG_LEN
   sm->sig_job = rs_sig_begin((size_t)blocklen,
 							 (size_t)RS_DEFAULT_STRONG_LEN);
+#else
+  sm->sig_job = rs_sig_begin((size_t)blocklen,
+							 (size_t)8, RS_MD4_SIG_MAGIC);
+#endif
   return (PyObject*)sm;
 }
 
