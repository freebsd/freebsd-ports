--- pyreadr/librdata.c.orig	2021-12-02 16:19:42 UTC
+++ pyreadr/librdata.c
@@ -4,8 +4,6 @@
 {
     "distutils": {
         "depends": [
-            "pyreadr/libs/librdata/src/rdata.h",
-            "pyreadr/libs/librdata/src/rdata_io_unistd.h"
         ],
         "extra_compile_args": [
             "-DHAVE_ZLIB",
@@ -23,13 +21,6 @@
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
@@ -655,8 +646,8 @@ static CYTHON_INLINE float __PYX_NAN() {
 #include <time.h>
 #include <stdint.h>
 #include <sys/types.h>
-#include "libs/librdata/src/rdata.h"
-#include "libs/librdata/src/rdata_io_unistd.h"
+#include <rdata.h>
+#include <rdata_io_unistd.h>
 #include <sys/stat.h>
 #include <unistd.h>
 #include <fcntl.h>
