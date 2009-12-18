--- smime.c.orig	2009-10-16 19:37:47.000000000 +0400
+++ smime.c	2009-10-29 23:46:33.000000000 +0300
@@ -94,9 +94,6 @@
 #include <stdio.h>
 #include <string.h>
 #include <stdlib.h>
-#ifndef macintosh
-# include <malloc.h>
-#endif
 
 #define DETACHED_SIG_TYPE_FILE  "application/x-detached-file-signature-file"
 
