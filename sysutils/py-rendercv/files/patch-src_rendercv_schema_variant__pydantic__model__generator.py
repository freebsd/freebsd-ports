--- src/rendercv/schema/variant_pydantic_model_generator.py.orig	2026-03-11 16:54:44 UTC
+++ src/rendercv/schema/variant_pydantic_model_generator.py
@@ -6,7 +6,7 @@ from rendercv.exception import RenderCVInternalError
 
 from rendercv.exception import RenderCVInternalError
 
-type FieldSpec = tuple[type[Any], FieldInfo]
+FieldSpec = tuple[type[Any], FieldInfo]
 
 
 def sanitize_defaults(value: Any) -> Any:
@@ -29,16 +29,16 @@ def sanitize_defaults(value: Any) -> Any:
     return value
 
 
-def create_variant_pydantic_model[T: pydantic.BaseModel](
+def create_variant_pydantic_model(
     *,
     variant_name: str,
     defaults: dict[str, Any],
-    base_class: type[T],
+    base_class,
     discriminator_field: str,
     class_name_suffix: str,
     module_name: str,
     require_all_fields: bool = False,
-) -> type[T]:
+):
     """Create Pydantic model variant with customized defaults.
 
     Why:
@@ -261,10 +261,10 @@ def create_discriminator_field_spec(
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
