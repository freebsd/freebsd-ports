--- tree_sitter_language_pack/__init__.py.orig	2025-09-23 06:46:36 UTC
+++ tree_sitter_language_pack/__init__.py
@@ -6,9 +6,9 @@ from typing import Literal, cast
 from pathlib import Path
 from typing import Literal, cast
 
-import tree_sitter_c_sharp
-import tree_sitter_embedded_template
-import tree_sitter_yaml
+#import tree_sitter_c_sharp
+#import tree_sitter_embedded_template
+#import tree_sitter_yaml
 from tree_sitter import Language, Parser
 
 SupportedLanguage = Literal[
@@ -35,7 +35,6 @@ SupportedLanguage = Literal[
     "commonlisp",
     "cpon",
     "cpp",
-    "csharp",
     "css",
     "csv",
     "cuda",
@@ -47,7 +46,6 @@ SupportedLanguage = Literal[
     "elisp",
     "elixir",
     "elm",
-    "embeddedtemplate",
     "erlang",
     "fennel",
     "firrtl",
@@ -179,7 +177,6 @@ SupportedLanguage = Literal[
     "wgsl",
     "xcompose",
     "xml",
-    "yaml",
     "yuck",
     "zig",
     "magik",
