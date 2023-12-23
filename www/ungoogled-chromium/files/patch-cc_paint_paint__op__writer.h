--- cc/paint/paint_op_writer.h.orig	2023-12-23 12:33:28 UTC
+++ cc/paint/paint_op_writer.h
@@ -122,10 +122,17 @@ class CC_PAINT_EXPORT PaintOpWriter {
   // easier to keep serialized size calculation in sync with serialization and
   // deserialization, and make it possible to allow dynamic sizing for some
   // data types (see the specialized/overloaded functions).
+#if defined(__clang__) && (__clang_major__ >= 15)
   template <typename T>
   static constexpr size_t SerializedSize();
   template <typename T>
   static constexpr size_t SerializedSize(const T& data);
+#else
+  template <typename T>
+  static size_t SerializedSize();
+  template <typename T>
+  static size_t SerializedSize(const T& data);
+#endif
   static size_t SerializedSize(const PaintImage& image);
   static size_t SerializedSize(const PaintRecord& record);
   static size_t SerializedSize(const SkHighContrastConfig& config);
@@ -463,12 +470,20 @@ constexpr size_t PaintOpWriter::SerializedSize<SkGainm
 }
 
 template <typename T>
+#if defined(__clang__) && (__clang_major__ >= 15)
 constexpr size_t PaintOpWriter::SerializedSize() {
+#else
+size_t PaintOpWriter::SerializedSize() {
+#endif
   static_assert(std::is_arithmetic_v<T> || std::is_enum_v<T>);
   return SerializedSizeSimple<T>();
 }
 template <typename T>
+#if defined(__clang__) && (__clang_major__ >= 15)
 constexpr size_t PaintOpWriter::SerializedSize(const T& data) {
+#else
+size_t PaintOpWriter::SerializedSize(const T& data) {
+#endif
   return SerializedSizeSimple<T>();
 }
 
