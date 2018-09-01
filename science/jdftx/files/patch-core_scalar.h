--- core/scalar.h.orig	2018-08-24 15:03:02 UTC
+++ core/scalar.h
@@ -54,7 +54,7 @@ template<class T> T ceildiv(T num, T den
 //! Return largest multiple of den smaller than num, templated over int types
 template<class T> T floorMultiple(T num, T den) { return (num/den)*den; }
 
-#ifdef __APPLE__
+#ifdef MISSING_SINCOS_FUNCTION
 #ifndef __in_a_cu_file__
 inline void sincos(double x, double* s, double* c)
 {	*s = sin(x);
