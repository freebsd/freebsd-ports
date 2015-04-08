--- src/appli/cs_partition.c.orig	2012-07-05 16:54:42 UTC
+++ src/appli/cs_partition.c
@@ -117,6 +117,7 @@ void METIS_PartGraphKway(int *, idxtype 
 
 #if defined(HAVE_SCOTCH)
 
+#include <stdint.h>
 #include <scotch.h>
 
 #endif
