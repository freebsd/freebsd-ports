--- src/3rdparty/chromium/net/cert/crl_set.cc.orig	2019-05-23 12:39:34 UTC
+++ src/3rdparty/chromium/net/cert/crl_set.cc
@@ -6,6 +6,7 @@
 
 #include "base/base64.h"
 #include "base/json/json_reader.h"
+#include "base/sys_byteorder.h"
 #include "base/time/time.h"
 #include "base/trace_event/trace_event.h"
 #include "base/values.h"
@@ -44,9 +45,9 @@ base::DictionaryValue* ReadHeader(base::StringPiece* d
   uint16_t header_len;
   if (data->size() < sizeof(header_len))
     return nullptr;
-  // Assumes little-endian.
   memcpy(&header_len, data->data(), sizeof(header_len));
   data->remove_prefix(sizeof(header_len));
+  header_len = base::ByteSwapToLE16(header_len);
 
   if (data->size() < header_len)
     return nullptr;
@@ -79,9 +80,9 @@ bool ReadCRL(base::StringPiece* data,
   uint32_t num_serials;
   if (data->size() < sizeof(num_serials))
     return false;
-  // Assumes little endian.
   memcpy(&num_serials, data->data(), sizeof(num_serials));
   data->remove_prefix(sizeof(num_serials));
+  num_serials = base::ByteSwapToLE32(num_serials);
 
   if (num_serials > 32 * 1024 * 1024)  // Sanity check.
     return false;
@@ -192,15 +193,6 @@ CRLSet::~CRLSet() = default;
 // static
 bool CRLSet::Parse(base::StringPiece data, scoped_refptr<CRLSet>* out_crl_set) {
   TRACE_EVENT0(NetTracingCategory(), "CRLSet::Parse");
-// Other parts of Chrome assume that we're little endian, so we don't lose
-// anything by doing this.
-#if defined(__BYTE_ORDER)
-  // Linux check
-  static_assert(__BYTE_ORDER == __LITTLE_ENDIAN, "assumes little endian");
-#elif defined(__BIG_ENDIAN__)
-// Mac check
-#error assumes little endian
-#endif
 
   std::unique_ptr<base::DictionaryValue> header_dict(ReadHeader(&data));
   if (!header_dict.get())
