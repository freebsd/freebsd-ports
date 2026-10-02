--- src/snapshot/startup-serializer.cc.orig	2026-05-30 07:48:33 UTC
+++ src/snapshot/startup-serializer.cc
@@ -77,8 +77,14 @@ StartupSerializer::StartupSerializer(
   ExternalReferenceTable* table = isolate->external_reference_table();
   for (uint32_t i = 0; i < ExternalReferenceTable::kSizeIsolateIndependent;
        ++i) {
-    ExternalReferenceEncoder::Value encoded_reference =
-        EncodeExternalReference(table->address(i));
+    // On FreeBSD the encoder map may be built before
+    // InitializeOncePerIsolateGroup populates all table entries, leaving some
+    // addresses missing from the map.  Such entries have unique addresses (not
+    // ICF-deduplicated), so they do not need deduplication records.
+    Maybe<ExternalReferenceEncoder::Value> maybe =
+        TryEncodeExternalReference(table->address(i));
+    if (maybe.IsNothing()) continue;
+    ExternalReferenceEncoder::Value encoded_reference = maybe.FromJust();
     if (encoded_reference.index() != i) {
       sink_.PutUint30(i, "expected reference index");
       sink_.PutUint30(encoded_reference.index(), "actual reference index");
