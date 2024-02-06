--- third_party/perfetto/src/trace_processor/db/column.h.orig	2024-02-06 12:08:38 UTC
+++ third_party/perfetto/src/trace_processor/db/column.h
@@ -48,6 +48,12 @@ template <>
 struct ColumnTypeHelper<int64_t> {
   static constexpr ColumnType ToColumnType() { return ColumnType::kInt64; }
 };
+#if (defined(__OpenBSD__) || defined(__FreeBSD__)) && defined(__i386__)
+template <>
+struct ColumnTypeHelper<long double> {
+  static constexpr ColumnType ToColumnType() { return ColumnType::kDouble; }
+};
+#endif
 template <>
 struct ColumnTypeHelper<double> {
   static constexpr ColumnType ToColumnType() { return ColumnType::kDouble; }
