--- src/c2f.h.orig	2018-03-21 00:24:56 UTC
+++ src/c2f.h
@@ -4,6 +4,7 @@
  */
 
 #include "config.h"
+#include <sys/types.h>
 
 #define ALL_CINT_FORTRAN_(NAME) \
 int c##NAME##_sph_(double *out, int *shls, int *atm, int *natm, \
