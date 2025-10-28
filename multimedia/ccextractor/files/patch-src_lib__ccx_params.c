--- src/lib_ccx/params.c.orig	2021-12-15 17:05:37 UTC
+++ src/lib_ccx/params.c
@@ -1,7 +1,7 @@
-#include "png.h"
-#include "protobuf-c.h"
-#include "zlib.h"
-#include "gpac/version.h"
+#include <png.h>
+#include <protobuf-c.h>
+#include <zlib.h>
+#include <gpac/version.h>
 #include "lib_ccx.h"
 #include "ccx_common_option.h"
 #include "utility.h"
@@ -10,10 +10,10 @@
 #include "ccx_common_common.h"
 #include "ccx_decoders_708.h"
 #include "compile_info.h"
-#include "../lib_hash/sha2.h"
+#include <sha256.h>
 #include <string.h>
 #include <stdio.h>
-#include <utf8proc/utf8proc.h>
+#include <utf8proc.h>
 
 #ifdef ENABLE_OCR
 #include <tesseract/capi.h>
