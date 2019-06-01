--- src/lib/libast/comp/setlocale.c.orig	2017-11-30 22:35:04 UTC
+++ src/lib/libast/comp/setlocale.c
@@ -38,6 +38,7 @@
 #include <namval.h>
 #include <iconv.h>
 #include <codeset.h>
+#include <errno.h>
 
 #if ( _lib_wcwidth || _lib_wctomb ) && _hdr_wctype
 #include <wctype.h>
