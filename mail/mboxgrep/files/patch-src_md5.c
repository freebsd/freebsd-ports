--- src/md5.c.orig	2023-02-24 22:59:50 UTC
+++ src/md5.c
@@ -26,32 +26,15 @@
 
 #include <sys/types.h>
 
-#if STDC_HEADERS || defined _LIBC
 # include <stdlib.h>
 # include <string.h>
-#else
-# ifndef HAVE_MEMCPY
-#  define memcpy(d, s, n) bcopy ((s), (d), (n))
-# endif
-#endif
 
 #include "md5.h"
 
-#ifdef _LIBC
-# include <endian.h>
-# if __BYTE_ORDER == __BIG_ENDIAN
+#include <sys/endian.h>
+# if _BYTE_ORDER == _BIG_ENDIAN
 #  define WORDS_BIGENDIAN 1
 # endif
-/* We need to keep the namespace clean so define the MD5 function
-   protected using leading __ .  */
-# define md5_init_ctx __md5_init_ctx
-# define md5_process_block __md5_process_block
-# define md5_process_bytes __md5_process_bytes
-# define md5_finish_ctx __md5_finish_ctx
-# define md5_read_ctx __md5_read_ctx
-# define md5_stream __md5_stream
-# define md5_buffer __md5_buffer
-#endif
 
 #ifdef WORDS_BIGENDIAN
 # define SWAP(n)							\
