--- src/asn1Coding.c.orig	Tue Jan  7 05:39:32 2003
+++ src/asn1Coding.c	Tue Jan  7 05:39:36 2003
@@ -28,7 +28,7 @@
 #include <stdio.h>
 #include <string.h>
 #include <libtasn1.h>
-#include <malloc.h>
+#include <stdlib.h>
 #include <config.h>
 
 #ifdef HAVE_GETOPT_H
