--- cargo-crates/font-kit-0.6.0/src/loaders/freetype.rs.orig	2020-04-14 20:53:09 UTC
+++ cargo-crates/font-kit-0.6.0/src/loaders/freetype.rs
@@ -15,7 +15,9 @@
 
 use byteorder::{BigEndian, ReadBytesExt};
 use freetype::freetype::{FT_Byte, FT_Done_Face, FT_Error, FT_Face, FT_FACE_FLAG_FIXED_WIDTH};
-use freetype::freetype::{FT_Fixed, FT_Get_Char_Index, FT_Get_Name_Index, FT_Get_Postscript_Name};
+use freetype::freetype::{
+    FT_Fixed, FT_Get_Char_Index, FT_Get_Name_Index, FT_Get_Postscript_Name, FT_Pos,
+};
 use freetype::freetype::{FT_Get_Sfnt_Table, FT_Init_FreeType, FT_LcdFilter, FT_Library};
 use freetype::freetype::{FT_Library_SetLcdFilter, FT_Load_Glyph, FT_LOAD_DEFAULT};
 use freetype::freetype::{FT_Load_Sfnt_Table, FT_Long, FT_Matrix, FT_New_Memory_Face};
@@ -801,14 +803,14 @@ impl Font {
             let vector = transform.vector.f32_to_ft_fixed_26_6();
 
             let mut delta = FT_Vector {
-                x: vector.x() as i64,
-                y: -vector.y() as i64,
+                x: vector.x() as FT_Pos,
+                y: -vector.y() as FT_Pos,
             };
             let mut ft_shape = FT_Matrix {
-                xx: matrix.x() as i64,
-                xy: matrix.y() as i64,
-                yx: matrix.z() as i64,
-                yy: matrix.w() as i64,
+                xx: matrix.x() as FT_Fixed,
+                xy: matrix.y() as FT_Fixed,
+                yx: matrix.z() as FT_Fixed,
+                yy: matrix.w() as FT_Fixed,
             };
             FT_Set_Transform(self.freetype_face, &mut ft_shape, &mut delta);
 
