--- pyreadr/librdata.c.orig	2023-08-09 09:41:49 UTC
+++ pyreadr/librdata.c
@@ -5,8 +5,6 @@
     "distutils": {
         "depends": [
             "pyreadr/conditional_includes.h",
-            "pyreadr/libs/librdata/src/rdata.h",
-            "pyreadr/libs/librdata/src/rdata_io_unistd.h"
         ],
         "extra_compile_args": [
             "-DHAVE_ZLIB",
@@ -24,13 +22,6 @@
         "name": "pyreadr.librdata",
         "sources": [
             "pyreadr/librdata.pyx",
-            "pyreadr/libs/librdata/src/rdata_write.c",
-            "pyreadr/libs/librdata/src/rdata_bits.c",
-            "pyreadr/libs/librdata/src/rdata_read.c",
-            "pyreadr/libs/librdata/src/rdata_parser.c",
-            "pyreadr/libs/librdata/src/CKHashTable.c",
-            "pyreadr/libs/librdata/src/rdata_error.c",
-            "pyreadr/libs/librdata/src/rdata_io_unistd.c"
         ]
     },
     "module_name": "pyreadr.librdata"
@@ -1117,8 +1108,8 @@ static CYTHON_INLINE float __PYX_NAN() {
 #include <time.h>
 #include <stdint.h>
 #include <sys/types.h>
-#include "libs/librdata/src/rdata.h"
-#include "libs/librdata/src/rdata_io_unistd.h"
+#include <rdata.h>
+#include <rdata_io_unistd.h>
 #include "conditional_includes.h"
 #include <string.h>
 #ifdef _OPENMP
