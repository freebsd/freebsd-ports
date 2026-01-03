--- src/rendercv/schema/override_dictionary.py.orig	2026-01-03 20:46:35 UTC
+++ src/rendercv/schema/override_dictionary.py
@@ -3,12 +3,12 @@ from rendercv.exception import RenderCVUserError
 from rendercv.exception import RenderCVUserError
 
 
-def update_value_by_location[T: dict | list](
-    dict_or_list: T,
+def update_value_by_location(
+    dict_or_list,
     key: str,
     value: str,
     full_key: str,
-) -> T:
+):
     """Navigate nested structure via dotted path and update value.
 
     Why:
@@ -85,10 +85,10 @@ def update_value_by_location[T: dict | list](
     return dict_or_list
 
 
-def apply_overrides_to_dictionary[T: dict](
-    dictionary: T,
+def apply_overrides_to_dictionary(
+    dictionary,
     overrides: dict[str, str],
-) -> T:
+):
     """Apply multiple CLI overrides to dictionary.
 
     Why:
