--- src/rendercv/renderer/templater/entry_templates_from_input.py.orig	2025-12-20 00:49:48 UTC
+++ src/rendercv/renderer/templater/entry_templates_from_input.py
@@ -14,14 +14,14 @@ uppercase_word_pattern = re.compile(r"\b[A-Z_]+\b")
 uppercase_word_pattern = re.compile(r"\b[A-Z_]+\b")
 
 
-def render_entry_templates[EntryType: Entry](
-    entry: EntryType,
+def render_entry_templates(
+    entry,
     *,
     templates: Templates,
     locale: Locale,
     show_time_span: bool,
     current_date: Date,
-) -> EntryType:
+):
     """Expand entry templates by substituting field placeholders with processed values.
 
     Why:
