--- src/rendercv/schema/models/cv/entries/bases/entry_with_complex_fields.py.orig	2025-12-19 21:42:57 UTC
+++ src/rendercv/schema/models/cv/entries/bases/entry_with_complex_fields.py
@@ -37,7 +37,7 @@ def validate_exact_date(date: str | int) -> str | int:
     return date
 
 
-type ExactDate = Annotated[str | int, pydantic.AfterValidator(validate_exact_date)]
+ExactDate = Annotated[str | int, pydantic.AfterValidator(validate_exact_date)]
 
 
 def get_date_object(date: str | int, current_date: Date | None = None) -> Date:
