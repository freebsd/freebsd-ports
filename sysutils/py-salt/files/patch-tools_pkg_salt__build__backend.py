--- tools/pkg/salt_build_backend.py.orig	2026-06-28 09:48:25 UTC
+++ tools/pkg/salt_build_backend.py
@@ -7,10 +7,6 @@ from setuptools import build_meta as _orig
     sys.path.insert(0, PROJECT_ROOT)
 
 from setuptools import build_meta as _orig
-from setuptools.build_meta import build_editable as setuptools_build_editable
-from setuptools.build_meta import (
-    prepare_metadata_for_build_editable as setuptools_prepare_metadata,
-)
 
 try:
     from setuptools.build_meta import build_editable as setuptools_build_editable
@@ -221,6 +217,7 @@ def get_scripts(dist=None):
 
 
 def get_scripts(dist=None):
+    return []  # FreeBSD: console_scripts entry points only, avoid duplicate bin scripts
     is_windows = sys.platform.startswith("win")
     scripts = ["scripts/salt-call"]
 
