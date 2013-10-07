--- src/engine/encoding.cpp.orig	2003-11-21 08:45:11.000000000 +0000
+++ src/engine/encoding.cpp
@@ -30,6 +30,7 @@
  * GPL.
  */
 #include <errno.h>
+#include <sys/param.h>
 
 #include "encoding.h"
 #include "proc.h"
@@ -278,7 +279,12 @@ eFlag Recoder::conv(Sit S, CDesc cd, con
             errno = 0;
             iconv((iconv_t)(cd -> physCD), 
 #               ifdef SABLOT_ICONV_CAST_OK
+#if defined(__FreeBSD__) || \
+   (defined(__DragonFly__) && __DragonFly_version > 300502)
+                    (const char**)(&inbuf),
+#else
                     (char**)(&inbuf),
+#endif
 #               else
                     &inbuf,
 #               endif
