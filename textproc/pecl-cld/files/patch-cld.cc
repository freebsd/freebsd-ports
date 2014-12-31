--- cld.cc.orig	2011-11-15 01:13:43 UTC
+++ cld.cc
@@ -30,8 +30,9 @@
 #include <ctype.h>
 #define CLD_WINDOWS
 
-#include "encodings/compact_lang_det/compact_lang_det.h"
-#include "encodings/compact_lang_det/ext_lang_enc.h"
+#include "compact_lang_det.h"
+#include "ext_lang_enc.h"
+#include "lang_enc.h"
 #include "base/string_util.h"
 #include "cld_encodings.h"
 
