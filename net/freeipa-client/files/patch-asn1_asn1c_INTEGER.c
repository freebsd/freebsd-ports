--- asn1/asn1c/INTEGER.c.orig	2024-08-21 15:06:37 UTC
+++ asn1/asn1c/INTEGER.c
@@ -7,6 +7,7 @@
 #include <INTEGER.h>
 #include <asn_codecs_prim.h>	/* Encoder and decoder of a primitive type */
 #include <errno.h>
+#include <stdlib.h>
 
 /*
  * INTEGER basic type description.
