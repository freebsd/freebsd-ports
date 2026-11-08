--- third_party/iamf_tools/src/iamf/cli/codec/opus_decoder.h.orig	2026-09-25 15:26:43 UTC
+++ third_party/iamf_tools/src/iamf/cli/codec/opus_decoder.h
@@ -23,7 +23,7 @@
 #include "iamf/cli/codec/decoder_base.h"
 #include "iamf/obu/decoder_config/opus_decoder_config.h"
 #include "iamf/obu/substream_channel_count.h"
-#include "include/opus.h"
+#include "third_party/opus/src/include/opus.h"
 
 namespace iamf_tools {
 
