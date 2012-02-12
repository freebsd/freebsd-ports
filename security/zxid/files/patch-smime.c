--- smime.c.orig	2011-07-01 22:26:07.000000000 +0800
+++ smime.c	2011-07-13 10:41:01.570539385 +0800
@@ -94,9 +94,6 @@
 #include <stdio.h>
 #include <string.h>
 #include <stdlib.h>
-#ifndef macintosh
-# include <malloc.h>
-#endif
 
 #define DETACHED_SIG_TYPE_FILE  "application/x-detached-file-signature-file"
 
