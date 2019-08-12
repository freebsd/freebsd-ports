--- third_party/blink/renderer/platform/fonts/shaping/shape_result_inline_headers.h.orig	2019-07-29 20:52:32 UTC
+++ third_party/blink/renderer/platform/fonts/shaping/shape_result_inline_headers.h
@@ -251,37 +251,6 @@ struct ShapeResult::RunInfo : public RefCounted<ShapeR
     template <bool has_non_zero_glyph_offsets>
     struct iterator final {};
 
-    // For non-zero glyph offset array
-    template <>
-    struct iterator<true> final {
-      // The constructor for ShapeResult
-      explicit iterator(const GlyphOffsetArray& array)
-          : pointer(array.storage_.get()) {
-        DCHECK(pointer);
-      }
-
-      // The constructor for ShapeResultView
-      explicit iterator(const GlyphDataRange& range) : pointer(range.offsets) {
-        DCHECK(pointer);
-      }
-
-      GlyphOffset operator*() const { return *pointer; }
-      void operator++() { ++pointer; }
-
-      const GlyphOffset* pointer;
-    };
-
-    // For zero glyph offset array
-    template <>
-    struct iterator<false> final {
-      explicit iterator(const GlyphOffsetArray& array) {
-        DCHECK(!array.HasStorage());
-      }
-      explicit iterator(const GlyphDataRange& range) { DCHECK(!range.offsets); }
-      GlyphOffset operator*() const { return GlyphOffset(); }
-      void operator++() {}
-    };
-
     template <bool has_non_zero_glyph_offsets>
     iterator<has_non_zero_glyph_offsets> GetIterator() const {
       return iterator<has_non_zero_glyph_offsets>(*this);
@@ -493,6 +462,37 @@ struct ShapeResult::RunInfo : public RefCounted<ShapeR
   unsigned start_index_;
   unsigned num_characters_;
   float width_;
+};
+
+// For non-zero glyph offset array
+template <>
+struct ShapeResult::RunInfo::GlyphOffsetArray::iterator<true> final {
+  // The constructor for ShapeResult
+  explicit iterator(const GlyphOffsetArray& array)
+      : pointer(array.storage_.get()) {
+    DCHECK(pointer);
+  }
+
+  // The constructor for ShapeResultView
+  explicit iterator(const GlyphDataRange& range) : pointer(range.offsets) {
+    DCHECK(pointer);
+  }
+
+  GlyphOffset operator*() const { return *pointer; }
+  void operator++() { ++pointer; }
+
+  const GlyphOffset* pointer;
+};
+
+// For zero glyph offset array
+template <>
+struct ShapeResult::RunInfo::GlyphOffsetArray::iterator<false> final {
+  explicit iterator(const GlyphOffsetArray& array) {
+    DCHECK(!array.HasStorage());
+  }
+  explicit iterator(const GlyphDataRange& range) { DCHECK(!range.offsets); }
+  GlyphOffset operator*() const { return GlyphOffset(); }
+  void operator++() {}
 };
 
 // Find the range of HarfBuzzRunGlyphData for the specified character index
