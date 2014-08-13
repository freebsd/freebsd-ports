--- libddr_MD5.c.orig	2014-08-10 03:38:53.000000000 +0900
+++ libddr_MD5.c	2014-08-13 23:02:10.000000000 +0900
@@ -21,6 +21,7 @@
 #include "sha256.h"
 #include "sha512.h"
 #include "sha1.h"
+#include "ffs.h"
 
 #include <stdlib.h>
 #include <string.h>
@@ -36,7 +37,7 @@
 #endif
 
 #include <netinet/in.h>	/* For ntohl/htonl */
-#include <endian.h>
+#include <machine/endian.h>
 
 // TODO: pass at runtime rather than compile time
 #define HASH_DEBUG(x) if (state->debug) x
