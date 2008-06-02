--- dclib/core/ciconv.cpp.orig	2008-06-02 12:58:22.000000000 +0200
+++ dclib/core/ciconv.cpp	2008-06-02 12:59:00.000000000 +0200
@@ -20,7 +20,7 @@
 #endif
 
 #ifndef ICONV_CONST
-#define ICONV_CONST
+#define ICONV_CONST const
 #endif
 
 #include <stdio.h>
