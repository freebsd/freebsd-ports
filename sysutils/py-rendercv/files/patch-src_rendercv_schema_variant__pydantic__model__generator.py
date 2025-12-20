--- src/rendercv/schema/variant_pydantic_model_generator.py.orig	2025-12-19 21:48:58 UTC
+++ src/rendercv/schema/variant_pydantic_model_generator.py
@@ -6,17 +6,17 @@ from rendercv.exception import RenderCVInternalError
 
 from rendercv.exception import RenderCVInternalError
 
-type FieldSpec = tuple[type[Any], FieldInfo]
+FieldSpec = tuple[type[Any], FieldInfo]
 
 
-def create_variant_pydantic_model[T: pydantic.BaseModel](
+def create_variant_pydantic_model(
     variant_name: str,
     defaults: dict[str, Any],
-    base_class: type[T],
+    base_class,
     discriminator_field: str,
     class_name_suffix: str,
     module_name: str,
-) -> type[T]:
+):
     """Create Pydantic model variant with customized defaults.
 
     Why:
@@ -190,10 +190,10 @@ def create_discriminator_field_spec(
     return (cast(type[Any], field_annotation), new_field)
 
 
-def deep_merge_nested_object[T: pydantic.BaseModel](
-    base_nested_obj: T,
+def deep_merge_nested_object(
+    base_nested_obj,
     updates: dict[str, Any],
-) -> T:
+):
     """Recursively merge nested dictionary updates into Pydantic model instance.
 
     Why:
