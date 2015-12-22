--- CLD.xs.orig	2014-09-07 20:44:12 UTC
+++ CLD.xs
@@ -24,10 +24,9 @@ extern "C" {
 # define dNOOP
 #endif
 
-#include "encodings/compact_lang_det/compact_lang_det.h"
-#include "encodings/compact_lang_det/ext_lang_enc.h"
-#include "encodings/compact_lang_det/unittest_data.h"
-#include "encodings/proto/encodings.pb.h"
+#include "compact_lang_det.h"
+#include "ext_lang_enc.h"
+#include "encodings/public/encodings.h"
 
 MODULE = Lingua::Identify::CLD		PACKAGE = Lingua::Identify::CLD
 
