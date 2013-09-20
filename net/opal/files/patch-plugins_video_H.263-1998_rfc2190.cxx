--- plugins/video/H.263-1998/rfc2190.cxx.orig	2013-02-20 03:18:03.000000000 +0100
+++ plugins/video/H.263-1998/rfc2190.cxx	2013-07-09 00:32:54.000000000 +0200
@@ -25,7 +25,7 @@
 
 #include <iostream>
 #include <string.h>
-#include <malloc.h>
+#include <stdlib.h>
 
 
 const unsigned char PSC[3]      = { 0x00, 0x00, 0x80 };
