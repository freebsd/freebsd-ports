--- common/md5.c.orig	2017-07-05 07:48:23 UTC
+++ common/md5.c
@@ -29,7 +29,7 @@
 #include "md5.h"
 
 /* #ifdef _LIBC */
-# include <endian.h>
+# include <sys/endian.h>
 # if __BYTE_ORDER == __BIG_ENDIAN
 #  define WORDS_BIGENDIAN 1
 # endif
