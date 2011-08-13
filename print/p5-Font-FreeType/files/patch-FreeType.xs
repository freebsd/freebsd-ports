--- FreeType.xs.orig	2004-09-12 05:50:44.000000000 +0900
+++ FreeType.xs	2011-08-13 20:42:27.482201061 +0900
@@ -226,7 +226,7 @@
 #define QEFFT2_CALL_TIDY  FREETMPS; LEAVE;
 
 static int
-handle_move_to (FT_Vector *to, void *data)
+handle_move_to (const FT_Vector *to, void *data)
 {
     struct QefFT2_Outline_Decompose_Extra_ *extra = data;
     double x = QEFFT2_NUM(to->x), y = QEFFT2_NUM(to->y);
@@ -243,7 +243,7 @@
 }
 
 static int
-handle_line_to (FT_Vector *to, void *data)
+handle_line_to (const FT_Vector *to, void *data)
 {
     struct QefFT2_Outline_Decompose_Extra_ *extra = data;
     double x = QEFFT2_NUM(to->x), y = QEFFT2_NUM(to->y);
@@ -260,7 +260,7 @@
 }
 
 static int
-handle_conic_to (FT_Vector *control, FT_Vector *to, void *data)
+handle_conic_to (const FT_Vector *control, const FT_Vector *to, void *data)
 {
     struct QefFT2_Outline_Decompose_Extra_ *extra = data;
     double x = QEFFT2_NUM(to->x), y = QEFFT2_NUM(to->y);
@@ -292,7 +292,7 @@
 }
 
 static int
-handle_cubic_to (FT_Vector *control1, FT_Vector *control2, FT_Vector *to,
+handle_cubic_to (const FT_Vector *control1, const FT_Vector *control2, const FT_Vector *to,
                  void *data)
 {
     struct QefFT2_Outline_Decompose_Extra_ *extra = data;
@@ -805,7 +805,8 @@
             char_code = FT_Get_First_Char(face, &glyph_idx);
             while (glyph_idx) {
                 if (glyph_idx == glyph->index) {
-                    RETVAL = newSVuv((UV) glyph->char_code = char_code);
+                    glyph->char_code = char_code;
+                    RETVAL = newSVuv((UV) glyph->char_code);
                     break;
                 }
                 char_code = FT_Get_Next_Char(face, char_code, &glyph_idx);
