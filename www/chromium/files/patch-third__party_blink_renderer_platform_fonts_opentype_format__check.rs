--- third_party/blink/renderer/platform/fonts/opentype/format_check.rs.orig	2026-09-25 15:26:43 UTC
+++ third_party/blink/renderer/platform/fonts/opentype/format_check.rs
@@ -23,7 +23,7 @@ pub struct FontFormatInfo {
     format_flags: Option<FontFormatFlags>,
 }
 
-pub fn get_font_format_info(font_bytes: &[u8]) -> FontFormatInfo {
+pub fn get_font_format_info(font_bytes: &[u8]) -> Box<FontFormatInfo> {
     let file_ref = make_font_ref_internal(font_bytes, 0);
 
     match file_ref {
@@ -32,11 +32,11 @@ pub fn get_font_format_info(font_bytes: &[u8]) -> Font
                 font.table_directory().table_records().iter().map(|e| e.tag()).collect();
             let color_version = get_colr_version(&font);
             let avar_version = get_avar_version(&font);
-            FontFormatInfo {
+            Box::new(FontFormatInfo {
                 format_flags: Some(FontFormatFlags { table_tags, color_version, avar_version }),
-            }
+            })
         }
-        _ => FontFormatInfo::default(),
+        _ => Box::new(FontFormatInfo::default()),
     }
 }
 
@@ -44,10 +44,10 @@ fn get_colr_version(font_ref: &FontRef) -> Option<u16>
     Some(font_ref.colr().ok()?.version())
 }
 
-pub fn is_colrv1(format_info: &FontFormatInfo) -> bool {
+fn is_colrv1(format_info: &FontFormatInfo) -> bool {
     matches!(&format_info.format_flags, Some(FontFormatFlags { color_version: Some(1), .. }),)
 }
-pub fn is_colrv0(format_info: &FontFormatInfo) -> bool {
+fn is_colrv0(format_info: &FontFormatInfo) -> bool {
     matches!(&format_info.format_flags, Some(FontFormatFlags { color_version: Some(0), .. }),)
 }
 
@@ -56,7 +56,7 @@ fn get_avar_version(font_ref: &FontRef) -> Option<(u16
     Some((version.major, version.minor))
 }
 
-pub fn is_avar2(format_info: &FontFormatInfo) -> bool {
+fn is_avar2(format_info: &FontFormatInfo) -> bool {
     matches!(&format_info.format_flags, Some(FontFormatFlags { avar_version: Some((2, _)), .. }),)
 }
 
@@ -69,22 +69,39 @@ fn has_tags(format_info: &FontFormatInfo, query: &[Tag
     }
 }
 
-pub fn is_variable(format_info: &FontFormatInfo) -> bool {
+fn is_variable(format_info: &FontFormatInfo) -> bool {
     has_tags(format_info, &[Tag::new(b"fvar")])
 }
 
-pub fn is_sbix(format_info: &FontFormatInfo) -> bool {
+fn is_sbix(format_info: &FontFormatInfo) -> bool {
     has_tags(format_info, &[Tag::new(b"sbix")])
 }
 
-pub fn is_cbdt_cblc(format_info: &FontFormatInfo) -> bool {
+fn is_cbdt_cblc(format_info: &FontFormatInfo) -> bool {
     has_tags(format_info, &[Tag::new(b"CBDT"), Tag::new(b"CBLC")])
 }
 
-pub fn is_ebdt_eblc(format_info: &FontFormatInfo) -> bool {
+fn is_ebdt_eblc(format_info: &FontFormatInfo) -> bool {
     has_tags(format_info, &[Tag::new(b"EBDT"), Tag::new(b"EBLC")])
 }
 
-pub fn is_cff2(format_info: &FontFormatInfo) -> bool {
+fn is_cff2(format_info: &FontFormatInfo) -> bool {
     has_tags(format_info, &[Tag::new(b"CFF2")])
+}
+
+#[cxx::bridge(namespace = "font_format_check")]
+pub mod ffi {
+    extern "Rust" {
+        type FontFormatInfo;
+
+        fn get_font_format_info(font_bytes: &[u8]) -> Box<FontFormatInfo>;
+        fn is_colrv1(format_info: &FontFormatInfo) -> bool;
+        fn is_colrv0(format_info: &FontFormatInfo) -> bool;
+        fn is_cbdt_cblc(format_info: &FontFormatInfo) -> bool;
+        fn is_ebdt_eblc(format_info: &FontFormatInfo) -> bool;
+        fn is_variable(format_info: &FontFormatInfo) -> bool;
+        fn is_sbix(format_info: &FontFormatInfo) -> bool;
+        fn is_cff2(format_info: &FontFormatInfo) -> bool;
+        fn is_avar2(format_info: &FontFormatInfo) -> bool;
+    }
 }
