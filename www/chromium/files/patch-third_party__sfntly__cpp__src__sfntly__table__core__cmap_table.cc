--- third_party/sfntly/cpp/src/sfntly/table/core/cmap_table.cc	2013-07-03 23:54:15.000000000 -0400
+++ third_party/sfntly/cpp/src/sfntly/table/core/cmap_table.cc	2013-07-19 00:44:09.000000000 -0400
@@ -439,7 +439,7 @@
 }
 
 CMapTable::CMapFormat0::Builder::Builder(const CMapId& cmap_id)
-    : CMap::Builder(reinterpret_cast<ReadableFontData*>(NULL),
+    : CMap::Builder(static_cast<ReadableFontData*>(0),
                     CMapFormat::kFormat0,
                     cmap_id) {
 }
@@ -563,7 +563,7 @@
     : CMapTable::CMap::Builder(data ? down_cast<WritableFontData*>(
                                    data->Slice(offset, data->ReadUShort(
                                        offset + Offset::kFormat0Length)))
-                               : reinterpret_cast<WritableFontData*>(NULL),
+                               : static_cast<WritableFontData*>(0),
                                CMapFormat::kFormat2, cmap_id) {
   // TODO(arthurhsu): FIXIT: heavy lifting and leak, need fix.
 }
@@ -574,7 +574,7 @@
     : CMapTable::CMap::Builder(data ? down_cast<ReadableFontData*>(
                                    data->Slice(offset, data->ReadUShort(
                                        offset + Offset::kFormat0Length)))
-                               : reinterpret_cast<ReadableFontData*>(NULL),
+                               : static_cast<ReadableFontData*>(0),
                                CMapFormat::kFormat2, cmap_id) {
   // TODO(arthurhsu): FIXIT: heavy lifting and leak, need fix.
 }
@@ -958,7 +958,7 @@
 CMapTable::CMapFormat4::Builder::Builder(SegmentList* segments,
                                          IntegerList* glyph_id_array,
                                          const CMapId& cmap_id)
-    : CMap::Builder(reinterpret_cast<ReadableFontData*>(NULL),
+    : CMap::Builder(static_cast<ReadableFontData*>(0),
                     CMapFormat::kFormat4, cmap_id),
       segments_(segments->begin(), segments->end()),
       glyph_id_array_(glyph_id_array->begin(), glyph_id_array->end()) {
@@ -966,7 +966,7 @@
 }
 
 CMapTable::CMapFormat4::Builder::Builder(const CMapId& cmap_id)
-    : CMap::Builder(reinterpret_cast<ReadableFontData*>(NULL),
+    : CMap::Builder(static_cast<ReadableFontData*>(0),
                     CMapFormat::kFormat4, cmap_id) {
 }
 
