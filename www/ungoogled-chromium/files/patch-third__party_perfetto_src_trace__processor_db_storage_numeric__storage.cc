--- third_party/perfetto/src/trace_processor/db/storage/numeric_storage.cc.orig	2024-02-03 15:42:55 UTC
+++ third_party/perfetto/src/trace_processor/db/storage/numeric_storage.cc
@@ -267,8 +267,13 @@ BitVector NumericStorageBase::LinearSearchInternal(Fil
   } else if (const auto* i32 = std::get_if<int32_t>(&*val)) {
     auto* start = static_cast<const int32_t*>(data_) + range.start;
     TypedLinearSearch(*i32, start, op, builder);
+#if (defined(__OpenBSD__) || defined(__FreeBSD__)) && defined(__i386__)
+  } else if (const auto* db = std::get_if<long double>(&*val)) {
+    auto* start = static_cast<const long double*>(data_) + range.start;
+#else
   } else if (const auto* db = std::get_if<double>(&*val)) {
     auto* start = static_cast<const double*>(data_) + range.start;
+#endif
     TypedLinearSearch(*db, start, op, builder);
   } else {
     PERFETTO_DFATAL("Invalid");
