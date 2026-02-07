--- src/rendercv/schema/models/design/typst_dimension.py.orig	2025-12-19 21:33:37 UTC
+++ src/rendercv/schema/models/design/typst_dimension.py
@@ -29,4 +29,4 @@ def validate_typst_dimension(dimension: str) -> str:
     return dimension
 
 
-type TypstDimension = Annotated[str, pydantic.AfterValidator(validate_typst_dimension)]
+TypstDimension = Annotated[str, pydantic.AfterValidator(validate_typst_dimension)]
