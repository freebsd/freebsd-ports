--- httptools/parser/parser.c.orig	2021-04-26 15:52:02 UTC
+++ httptools/parser/parser.c
@@ -625,7 +625,7 @@ static CYTHON_INLINE float __PYX_NAN() {
 #include <stdio.h>
 #include "pythread.h"
 #include <stdint.h>
-#include "../../vendor/http-parser/http_parser.h"
+#include "http_parser.h"
 #ifdef _OPENMP
 #include <omp.h>
 #endif /* _OPENMP */
