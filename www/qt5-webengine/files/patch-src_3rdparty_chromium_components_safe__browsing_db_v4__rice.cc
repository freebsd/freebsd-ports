--- src/3rdparty/chromium/components/safe_browsing/db/v4_rice.cc.orig	2019-05-23 12:39:34 UTC
+++ src/3rdparty/chromium/components/safe_browsing/db/v4_rice.cc
@@ -8,6 +8,7 @@
 #include "base/logging.h"
 #include "base/numerics/safe_math.h"
 #include "base/strings/stringprintf.h"
+#include "base/sys_byteorder.h"
 #include "build/build_config.h"
 #include "components/safe_browsing/db/v4_rice.h"
 
@@ -21,10 +22,6 @@ using ::google::protobuf::RepeatedField;
 using ::google::protobuf::int32;
 using ::google::protobuf::int64;
 
-#if !defined(ARCH_CPU_LITTLE_ENDIAN) || (ARCH_CPU_LITTLE_ENDIAN != 1)
-#error The code below assumes little-endianness.
-#endif
-
 namespace safe_browsing {
 
 namespace {
@@ -117,7 +114,7 @@ V4DecodeResult V4RiceDecoder::DecodePrefixes(const int
   out->reserve((num_entries + 1));
 
   base::CheckedNumeric<uint32_t> last_value(first_value);
-  out->push_back(htonl(last_value.ValueOrDie()));
+  out->push_back(base::ByteSwap(static_cast<uint32_t>(last_value.ValueOrDie())));
 
   if (num_entries > 0) {
     V4RiceDecoder decoder(rice_parameter, num_entries, encoded_data);
@@ -136,7 +133,7 @@ V4DecodeResult V4RiceDecoder::DecodePrefixes(const int
 
       // This flipping is done so that the decoded uint32 is interpreted
       // correcly as a string of 4 bytes.
-      out->push_back(htonl(last_value.ValueOrDie()));
+      out->push_back(base::ByteSwap(static_cast<uint32_t>(last_value.ValueOrDie())));
     }
   }
 
