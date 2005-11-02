
$FreeBSD$

--- src/transform/wavelet.c.orig
+++ src/transform/wavelet.c
@@ -70,6 +70,7 @@
 { \
 	PyObject *tmp; \
 	FUNC_MESS_BEGIN(); \
+	{ \
         pygsl_transform_help_s helps;\
         struct _pygsl_transform_help_rf_s s; \
         helps.info = &wavelet_info; \
@@ -79,6 +80,7 @@
 	tmp = PyGSL_transform_((PyObject *) self, args, &helps); \
 	FUNC_MESS_END(); \
 	return tmp; \
+	} \
 }
 PYGSL_WAVLET(forward)
 PYGSL_WAVLET(inverse)
@@ -89,6 +91,7 @@
 { \
 	PyObject *tmp; \
 	FUNC_MESS_BEGIN(); \
+	{ \
         pygsl_transform_help_s helps;\
         struct _pygsl_transform_help_rf_s s; \
         helps.info = &wavelet_info; \
@@ -98,6 +101,7 @@
 	tmp = PyGSL_transform_2d_((PyObject *) self, args, &helps); \
 	FUNC_MESS_END(); \
 	return tmp; \
+	} \
 }
 PYGSL_WAVLET2D(,forward)
 PYGSL_WAVLET2D(,inverse)
