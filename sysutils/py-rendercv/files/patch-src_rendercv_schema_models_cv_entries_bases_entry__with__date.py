--- src/rendercv/schema/models/cv/entries/bases/entry_with_date.py.orig	2025-12-19 21:34:29 UTC
+++ src/rendercv/schema/models/cv/entries/bases/entry_with_date.py
@@ -31,7 +31,7 @@ def validate_arbitrary_date(date: int | str) -> int | 
     return date
 
 
-type ArbitraryDate = Annotated[
+ArbitraryDate = Annotated[
     int | str, pydantic.AfterValidator(validate_arbitrary_date)
 ]
 
