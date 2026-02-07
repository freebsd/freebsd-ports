--- xstream.h.orig	2020-08-06 02:32:59 UTC
+++ xstream.h
@@ -41,7 +41,7 @@ extern "C" int fseeko(FILE *, off_t, int);
 extern "C" off_t ftello(FILE *);
 #endif
 
-#ifdef __APPLE__
+if defined(__APPLE__) || defined(__FreeBSD__)
 #include <rpc/xdr.h>
 
 inline bool_t xdr_long(XDR *__xdrs, long *__lp) {
