-- Fix LGZ compression for Lean >= 4.33 non-8-byte-aligned constructor objects.
-- Lean 4.33 introduced constructor objects with non-8-byte-aligned sizes (e.g.,
-- a Bool field stored as 1 byte gives cs_sz=19 instead of the old 8-byte-rounded 24).
-- The old code asserted cs_sz & 7 == 0, which panics on such objects.
-- It also used (cs_sz >> 3) - 1 - num_fields to count scalar units, truncating to 0
-- for non-aligned objects, silently dropping scalar bytes from the compressed stream.
-- This patch removes the alignment assertion and fixes the scalar-field count to round
-- UP to the nearest 8-byte unit so the decompressor emits the correct scalar data.
-- The exprish path (Lean AST-specific encoding) keeps the legacy formula since those
-- types always have 8-byte-aligned scalars and we must not accidentally match their
-- hardcoded (ctor, num_fields, sfields) tuples.

--- src/lgz.rs.orig	2026-06-27 14:23:24 UTC
+++ src/lgz.rs
@@ -460,7 +460,7 @@ fn on_subobjs(cfg: Config, buf: &[u8], pos0: usize, mu
     tag::RESERVED => panic!("reserved"),
     _ctor => {
       let len_except_sfields = 8 + 8 * header.num_fields as usize;
-      assert!(len_except_sfields <= header.cs_sz.get() as usize && header.cs_sz.get() & 7 == 0);
+      assert!(len_except_sfields <= header.cs_sz.get() as usize); // Lean >= 4.33 uses non-8-byte-aligned ctor sizes
       on_array_subobjs(buf, header.num_fields.into(), pos, f);
       pos0 + header.cs_sz.get() as usize
     }
@@ -1351,9 +1351,13 @@ impl<W: Write> LgzWriter<'_, W> {
       }
       tag::CLOSURE | tag::STRUCT_ARRAY | tag::EXTERNAL | tag::RESERVED => unreachable!(),
       ctor => {
-        let sfields = (header.cs_sz.get() >> 3) - 1 - (header.num_fields as u16);
+        // Lean >= 4.33 uses non-8-byte-aligned scalar fields; use legacy formula for exprish
+        // path (Lean AST types always have 8-byte-aligned scalars), and round up for general path.
+        let sfields_legacy = (header.cs_sz.get() >> 3).saturating_sub(header.num_fields as u16 + 1);
+        let scalar_bytes = (header.cs_sz.get() as usize).saturating_sub(8 + 8 * header.num_fields as usize);
+        let sfields = ((scalar_bytes + 7) / 8) as u16;
         if !ENABLE_EXPRISH
-          || self.try_write_exprish_ctor(pos, mode, ctor, header.num_fields, sfields).is_none()
+          || self.try_write_exprish_ctor(pos, mode, ctor, header.num_fields, sfields_legacy).is_none()
         {
           if let Some(packed) = pack_ctor(ctor, header.num_fields, sfields) {
             self.write_op(mode, LgzMode::Normal, packed);
