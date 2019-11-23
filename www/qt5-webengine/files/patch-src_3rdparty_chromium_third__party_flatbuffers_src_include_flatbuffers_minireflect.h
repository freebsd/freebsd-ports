--- src/3rdparty/chromium/third_party/flatbuffers/src/include/flatbuffers/minireflect.h.orig	2019-05-23 12:39:34 UTC
+++ src/3rdparty/chromium/third_party/flatbuffers/src/include/flatbuffers/minireflect.h
@@ -122,58 +122,58 @@ inline void IterateValue(ElementaryType type, const ui
                          soffset_t vector_index, IterationVisitor *visitor) {
   switch (type) {
     case ET_UTYPE: {
-      auto tval = *reinterpret_cast<const uint8_t *>(val);
+      auto tval = ReadScalar<uint8_t>(val);
       visitor->UType(tval, EnumName(tval, type_table));
       break;
     }
     case ET_BOOL: {
-      visitor->Bool(*reinterpret_cast<const uint8_t *>(val) != 0);
+      visitor->Bool(ReadScalar<uint8_t>(val) != 0);
       break;
     }
     case ET_CHAR: {
-      auto tval = *reinterpret_cast<const int8_t *>(val);
+      auto tval = ReadScalar<int8_t>(val);
       visitor->Char(tval, EnumName(tval, type_table));
       break;
     }
     case ET_UCHAR: {
-      auto tval = *reinterpret_cast<const uint8_t *>(val);
+      auto tval = ReadScalar<uint8_t>(val);
       visitor->UChar(tval, EnumName(tval, type_table));
       break;
     }
     case ET_SHORT: {
-      auto tval = *reinterpret_cast<const int16_t *>(val);
+      auto tval = ReadScalar<int16_t>(val);
       visitor->Short(tval, EnumName(tval, type_table));
       break;
     }
     case ET_USHORT: {
-      auto tval = *reinterpret_cast<const uint16_t *>(val);
+      auto tval = ReadScalar<uint16_t>(val);
       visitor->UShort(tval, EnumName(tval, type_table));
       break;
     }
     case ET_INT: {
-      auto tval = *reinterpret_cast<const int32_t *>(val);
+      auto tval = ReadScalar<int32_t>(val);
       visitor->Int(tval, EnumName(tval, type_table));
       break;
     }
     case ET_UINT: {
-      auto tval = *reinterpret_cast<const uint32_t *>(val);
+      auto tval = ReadScalar<uint32_t>(val);
       visitor->UInt(tval, EnumName(tval, type_table));
       break;
     }
     case ET_LONG: {
-      visitor->Long(*reinterpret_cast<const int64_t *>(val));
+      visitor->Long(ReadScalar<int64_t>(val));
       break;
     }
     case ET_ULONG: {
-      visitor->ULong(*reinterpret_cast<const uint64_t *>(val));
+      visitor->ULong(ReadScalar<uint64_t>(val));
       break;
     }
     case ET_FLOAT: {
-      visitor->Float(*reinterpret_cast<const float *>(val));
+      visitor->Float(ReadScalar<float>(val));
       break;
     }
     case ET_DOUBLE: {
-      visitor->Double(*reinterpret_cast<const double *>(val));
+      visitor->Double(ReadScalar<double>(val));
       break;
     }
     case ET_STRING: {
