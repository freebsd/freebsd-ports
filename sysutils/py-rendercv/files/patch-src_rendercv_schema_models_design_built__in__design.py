--- src/rendercv/schema/models/design/built_in_design.py.orig	1970-01-01 00:00:00 UTC
+++ src/rendercv/schema/models/design/built_in_design.py
@@ -37,14 +37,13 @@ def discover_other_themes() -> list[type[ClassicTheme]
 
     return discovered
 
+discovered_other_themes = discover_other_themes()
 
 # Build discriminated union dynamically
-type BuiltInDesign = Annotated[
-    ClassicTheme | reduce(or_, discover_other_themes()),  # ty: ignore[invalid-type-form]
+BuiltInDesign = Annotated[
+    ClassicTheme | reduce(or_, discovered_other_themes),  # ty: ignore[invalid-type-form]
     pydantic.Field(discriminator="theme"),
 ]
-available_themes: list[str] = [
-    ThemeClass.model_fields["theme"].default
-    for ThemeClass in get_args(get_args(BuiltInDesign.__value__)[0])
-]
+discovered_other_themes.append(ClassicTheme)
+available_themes: list[str] = [ThemeClass.model_fields["theme"].default for ThemeClass in discovered_other_themes]
 built_in_design_adapter = pydantic.TypeAdapter(BuiltInDesign)
