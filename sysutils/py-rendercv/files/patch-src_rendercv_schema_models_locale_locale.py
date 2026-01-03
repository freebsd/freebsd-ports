--- src/rendercv/schema/models/locale/locale.py.orig	1970-01-01 00:00:00 UTC
+++ src/rendercv/schema/models/locale/locale.py
@@ -37,14 +37,13 @@ def discover_other_locales() -> list[type[EnglishLocal
 
     return discovered
 
+discovered_other_locales = discover_other_locales()
 
 # Build discriminated union dynamically
-type Locale = Annotated[
-    EnglishLocale | reduce(or_, discover_other_locales()),  # ty: ignore[invalid-type-form]
+Locale = Annotated[
+    EnglishLocale | reduce(or_, discovered_other_locales),  # ty: ignore[invalid-type-form]
     pydantic.Field(discriminator="language"),
 ]
-available_locales = [
-    LocaleModel.model_fields["language"].default
-    for LocaleModel in get_args(get_args(Locale.__value__)[0])
-]
+discovered_other_locales.append(EnglishLocale)
+available_locales = [LocaleModel.model_fields["language"].default for LocaleModel in discovered_other_locales]
 locale_adapter = pydantic.TypeAdapter(Locale)
