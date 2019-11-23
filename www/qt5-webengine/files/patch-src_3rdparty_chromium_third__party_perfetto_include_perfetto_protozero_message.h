--- src/3rdparty/chromium/third_party/perfetto/include/perfetto/protozero/message.h.orig	2019-05-23 12:39:34 UTC
+++ src/3rdparty/chromium/third_party/perfetto/include/perfetto/protozero/message.h
@@ -138,6 +138,13 @@ class PERFETTO_EXPORT Message {
 
     pos = proto_utils::WriteVarInt(proto_utils::MakeTagFixed<T>(field_id), pos);
     memcpy(pos, &value, sizeof(T));
+#if __BYTE_ORDER__ != __ORDER_LITTLE_ENDIAN__
+    for (size_t i = sizeof(T)/2; i--; ) {
+      uint8_t tmp = pos[i];
+      pos[i] = pos[sizeof(T)-1-i];
+      pos[sizeof(T)-1-i] = tmp;
+    }
+#endif
     pos += sizeof(T);
     // TODO: Optimize memcpy performance, see http://crbug.com/624311 .
     WriteToStream(buffer, pos);
