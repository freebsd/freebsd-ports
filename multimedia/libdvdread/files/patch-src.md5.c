--- src/md5.c.orig	2011-12-09 11:27:02.423821748 +0100
+++ src/md5.c	2011-12-09 11:29:07.409821303 +0100
@@ -28,12 +28,7 @@
 #include "md5.h"
 /* #include "unlocked-io.h" */
 
-#ifdef _LIBC
-# include <endian.h>
-# if __BYTE_ORDER == __BIG_ENDIAN
-#  define WORDS_BIGENDIAN 1
-# endif
-#endif
+#include "config.h"
 
 #ifdef WORDS_BIGENDIAN
 # define SWAP(n)                                                        \
