--- third_party/iamf_tools/src/iamf/cli/codec/opus_decoder.cc.orig	2026-09-25 15:26:43 UTC
+++ third_party/iamf_tools/src/iamf/cli/codec/opus_decoder.cc
@@ -30,8 +30,8 @@
 #include "iamf/obu/decoder_config/opus_decoder_config.h"
 #include "iamf/obu/substream_channel_count.h"
 #include "iamf/obu/types.h"
-#include "include/opus.h"
-#include "include/opus_types.h"
+#include "third_party/opus/src/include/opus.h"
+#include "third_party/opus/src/include/opus_types.h"
 
 namespace iamf_tools {
 
