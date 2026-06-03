--- src/rendercv/schema/models/path.py.orig	2025-12-19 21:40:25 UTC
+++ src/rendercv/schema/models/path.py
@@ -60,14 +60,14 @@ def serialize_path(path: pathlib.Path) -> str:
     return str(path.relative_to(pathlib.Path.cwd()))
 
 
-type ExistingPathRelativeToInput = Annotated[
+ExistingPathRelativeToInput = Annotated[
     pathlib.Path,
     pydantic.AfterValidator(
         lambda path, info: resolve_relative_path(path, info, must_exist=True)
     ),
 ]
 
-type PlannedPathRelativeToInput = Annotated[
+PlannedPathRelativeToInput = Annotated[
     pathlib.Path,
     pydantic.AfterValidator(
         lambda path, info: resolve_relative_path(path, info, must_exist=False)
