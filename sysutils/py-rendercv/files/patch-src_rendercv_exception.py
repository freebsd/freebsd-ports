--- src/rendercv/exception.py.orig	2026-03-11 17:14:40 UTC
+++ src/rendercv/exception.py
@@ -1,14 +1,14 @@ from typing import Literal
 from dataclasses import dataclass, field
 from typing import Literal
 
-type YamlSource = Literal[
+YamlSource = Literal[
     "main_yaml_file",
     "design_yaml_file",
     "locale_yaml_file",
     "settings_yaml_file",
 ]
-type OverlaySourceKey = Literal["design", "locale", "settings"]
-type YamlLocation = tuple[tuple[int, int], tuple[int, int]]
+OverlaySourceKey = Literal["design", "locale", "settings"]
+YamlLocation = tuple[tuple[int, int], tuple[int, int]]
 
 OVERLAY_SOURCE_TO_YAML_SOURCE: dict[OverlaySourceKey, YamlSource] = {
     "design": "design_yaml_file",
