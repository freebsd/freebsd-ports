--- src/asn1Parser.c.orig	Tue Jan  7 05:38:03 2003
+++ src/asn1Parser.c	Tue Jan  7 05:38:09 2003
@@ -28,7 +28,7 @@
 #include <stdio.h>
 #include <string.h>
 #include <libtasn1.h>
-#include <malloc.h>
+#include <stdlib.h>
 #include <config.h>
 
 #ifdef HAVE_GETOPT_H
