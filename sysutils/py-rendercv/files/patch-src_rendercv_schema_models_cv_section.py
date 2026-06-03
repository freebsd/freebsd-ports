--- src/rendercv/schema/models/cv/section.py.orig	1970-01-01 00:00:00 UTC
+++ src/rendercv/schema/models/cv/section.py
@@ -21,7 +21,7 @@ from .entries.reversed_numbered import ReversedNumbere
 # Below needs to be updated when new entry types are added.
 
 # str is an entry type (TextEntry) but not a model, so it's not included in EntryModel.
-type EntryModel = (
+EntryModel = (
     OneLineEntry
     | NormalEntry
     | ExperienceEntry
@@ -31,13 +31,22 @@ type EntryModel = (
     | NumberedEntry
     | ReversedNumberedEntry
 )
-type Entry = EntryModel | str
+Entry = EntryModel | str
 ########################################################################################
-available_entry_models: tuple[type[EntryModel], ...] = get_args(EntryModel.__value__)
+available_entry_models: tuple[type[EntryModel], ...] = (
+    OneLineEntry,
+    NormalEntry,
+    ExperienceEntry,
+    EducationEntry,
+    PublicationEntry,
+    BulletEntry,
+    NumberedEntry,
+    ReversedNumberedEntry
+)
 available_entry_type_names: tuple[str, ...] = tuple(
     [entry_type.__name__ for entry_type in available_entry_models] + ["TextEntry"]
 )
-type ListOfEntries = list[str] | reduce(  # ty: ignore[invalid-type-form]
+ListOfEntries = list[str] | reduce(  # ty: ignore[invalid-type-form]
     or_, [list[entry_type] for entry_type in available_entry_models]
 )
 
@@ -244,7 +253,7 @@ def validate_section(sections_input: Any) -> Any:
 # Create a custom type named Section, which is a list of entries. The entries can be any
 # of the available entry types. The section is validated with the `validate_section`
 # function.
-type Section = Annotated[
+Section = Annotated[
     pydantic.json_schema.SkipJsonSchema[Any] | ListOfEntries,
     pydantic.BeforeValidator(lambda entries: validate_section(entries)),
 ]
