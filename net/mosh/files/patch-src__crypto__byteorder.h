--- ./src/crypto/byteorder.h.orig	2012-03-10 13:57:21.000000000 -0500
+++ ./src/crypto/byteorder.h	2012-04-10 15:28:42.000000000 -0400
@@ -22,7 +22,7 @@
 #include "config.h"
 
 #ifdef HAVE_HTOBE64
-# include <endian.h>
+# include <sys/endian.h>
 #elif HAVE_OSX_SWAP
 # include <libkern/OSByteOrder.h>
 # define htobe64 OSSwapHostToBigInt64
