--- src/rendercv/schema/models/design/font_family.py.orig	2025-12-19 21:33:15 UTC
+++ src/rendercv/schema/models/design/font_family.py
@@ -50,4 +50,4 @@ available_font_families = sorted(
 )
 
 
-type FontFamily = SkipJsonSchema[str] | Literal[*tuple(available_font_families)]  # pyright: ignore[reportInvalidTypeForm]
+FontFamily = SkipJsonSchema[str] | Literal[*tuple(available_font_families)]  # pyright: ignore[reportInvalidTypeForm]
