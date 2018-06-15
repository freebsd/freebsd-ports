--- xstream.h.orig	2018-06-10 15:14:47 UTC
+++ xstream.h
@@ -31,7 +31,7 @@
 #define quad_t long long
 #define u_quad_t unsigned long long
   
-#if defined(__CYGWIN__) || defined(__FreeBSD__)
+#if defined(__CYGWIN__)
 #include <sys/select.h>
 #define u_char unsigned char
 #define u_int unsigned int
@@ -41,6 +41,11 @@ extern "C" int fseeko(FILE *, off_t, int
 extern "C" off_t ftello(FILE *);
 #endif  
 
+#ifdef __FreeBSD__
+#define xdr_longlong_t xdr_int64_t
+#define xdr_u_longlong_t xdr_u_int64_t
+#endif
+
 #ifdef _POSIX_SOURCE
 #undef _POSIX_SOURCE
 #include <rpc/rpc.h>
