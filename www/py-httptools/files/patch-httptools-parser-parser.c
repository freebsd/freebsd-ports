--- httptools/parser/parser.c.orig	2019-02-25 19:54:42 UTC
+++ httptools/parser/parser.c
@@ -609,7 +609,7 @@ static CYTHON_INLINE float __PYX_NAN() {
 #include <stdio.h>
 #include "pythread.h"
 #include <stdint.h>
-#include "../../vendor/http-parser/http_parser.h"
+#include "http_parser.h"
 #ifdef _OPENMP
 #include <omp.h>
 #endif /* _OPENMP */
