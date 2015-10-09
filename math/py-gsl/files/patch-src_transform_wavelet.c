--- src/transform/wavelet.c.orig	2015-09-13 16:16:51 UTC
+++ src/transform/wavelet.c
@@ -147,6 +147,7 @@ PyGSL_wavelet_ ## direction(PyGSL_wavele
 { \
 	PyObject *tmp; \
 	FUNC_MESS_BEGIN(); \
+	{ \
         pygsl_transform_help_s helps;\
         struct _pygsl_transform_help_rf_s s; \
         helps.info = &wavelet_info; \
@@ -156,6 +157,7 @@ PyGSL_wavelet_ ## direction(PyGSL_wavele
 	tmp = PyGSL_transform_((PyObject *) self, args, &helps); \
 	FUNC_MESS_END(); \
 	return tmp; \
+	} \
 }
 PYGSL_WAVLET(forward)
 PYGSL_WAVLET(inverse)
@@ -166,6 +168,7 @@ PyGSL_wavelet2d_ ## type ## direction(Py
 { \
 	PyObject *tmp; \
 	FUNC_MESS_BEGIN(); \
+	{ \
         pygsl_transform_help_s helps;\
         struct _pygsl_transform_help_rf_s s; \
         helps.info = &wavelet_info; \
@@ -175,6 +178,7 @@ PyGSL_wavelet2d_ ## type ## direction(Py
 	tmp = PyGSL_transform_2d_((PyObject *) self, args, &helps); \
 	FUNC_MESS_END(); \
 	return tmp; \
+	} \
 }
 PYGSL_WAVLET2D(,forward)
 PYGSL_WAVLET2D(,inverse)
