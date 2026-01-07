--- src/mdformat/_conf.py.orig	2025-01-30 17:57:20 UTC
+++ src/mdformat/_conf.py
@@ -1,6 +1,6 @@ from __future__ import annotations
 from __future__ import annotations
 
-import functools
+import functools, os
 from pathlib import Path
 from types import MappingProxyType
 from typing import Mapping
@@ -35,7 +35,10 @@ def read_toml_opts(conf_dir: Path) -> tuple[Mapping, P
 @functools.lru_cache()
 def read_toml_opts(conf_dir: Path) -> tuple[Mapping, Path | None]:
     conf_path = conf_dir / ".mdformat.toml"
-    if not conf_path.is_file():
+    # conf_path.is_file() throws an exception when trying to access /net,
+    # a directory used only by autoconf with special attributes.
+    # https://github.com/hukkin/mdformat/issues/565#issuecomment-3697204512
+    if not os.path.isfile(str(conf_path)):
         parent_dir = conf_dir.parent
         if conf_dir == parent_dir:
             return {}, None
