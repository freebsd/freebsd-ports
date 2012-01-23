--- gen_allocdefs.h.orig	2012-01-23 20:49:57.000000000 -0200
+++ gen_allocdefs.h	2012-01-23 20:50:15.000000000 -0200
@@ -1,6 +1,8 @@
 #ifndef GEN_ALLOC_DEFS_H
 #define GEN_ALLOC_DEFS_H
 
+#include "alloc.h"
+
 #define GEN_ALLOC_ready(ta,type,field,len,a,i,n,x,base,ta_ready) \
 int ta_ready(x,n) register ta *x; register unsigned int n; \
 { register unsigned int i; \
