--- src/libsputext/xine_decoder.c.orig	Thu May 16 22:51:25 2002
+++ src/libsputext/xine_decoder.c	Thu May 16 22:51:33 2002
@@ -36,11 +36,7 @@
 #include <sys/stat.h>
 #include <fcntl.h>
 #include <ctype.h>
-#ifdef __FreeBSD__
-# include <sys/iconv.h>
-#else
-# include <iconv.h>
-#endif
+#include <iconv.h>
 
 #include "buffer.h"
 #include "events.h"
