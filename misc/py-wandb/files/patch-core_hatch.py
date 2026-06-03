-- Fix Go 1.25+ compilation of purego/fakecgo on FreeBSD without CGO.
-- The //go:cgo_export_dynamic directives in fakecgo/freebsd.go are only
-- allowed in CGO-generated code in Go 1.25+, but can be enabled by passing
-- -gcflags=-std for that package. Without exporting these symbols, the
-- wandb-core binary fails at runtime with "Undefined symbol environ".
-- See: https://github.com/ebitengine/purego/blob/v0.10.0/internal/fakecgo/freebsd.go

--- core/hatch.py.orig	2026-05-16 20:53:29 UTC
+++ core/hatch.py
@@ -4,6 +4,7 @@
 
 import os
 import pathlib
+import platform
 import shutil
 import subprocess
 from collections.abc import Mapping
@@ -57,6 +58,12 @@
 
     vendor_flags = ["-mod=vendor"]
 
+    # On FreeBSD without CGO, the fakecgo package uses //go:cgo_export_dynamic
+    # which requires the -std gcflag to be allowed in non-CGO code (Go 1.25+).
+    gcflags = []
+    if platform.system() == "FreeBSD" and not with_cgo:
+        gcflags = ["-gcflags=github.com/ebitengine/purego/internal/fakecgo=-std"]
+
     # We have to invoke Go from the directory with go.mod, hence the
     # paths relative to ./core
     subprocess.check_call(
@@ -66,6 +73,7 @@
             *build_tags,
             *coverage_flags,
             *race_detect_flags,
+            *gcflags,
             *ld_flags,
             *output_flags,
             *vendor_flags,
