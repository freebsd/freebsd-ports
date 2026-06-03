--- src/rendercv/schema/models/design/font_family.py.orig	1970-01-01 00:00:00 UTC
+++ src/rendercv/schema/models/design/font_family.py
@@ -50,4 +50,4 @@ available_font_families = sorted(
 )
 
 
-type FontFamily = SkipJsonSchema[str] | Literal[*tuple(available_font_families)]  # ty: ignore[invalid-type-form]
+FontFamily = SkipJsonSchema[str] | Literal[*tuple(available_font_families)]  # pyright: ignore[reportInvalidTypeForm]
