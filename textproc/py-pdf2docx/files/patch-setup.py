-- The sdist does not ship version.txt; setup.py then falls back to a stale
-- 0.5.6a1 version.  Use an environment variable supplied by the port so the
-- produced wheel matches DISTVERSION.

--- setup.py.orig	2026-05-01 03:54:00 UTC
+++ setup.py
@@ -37,7 +37,7 @@
 setup(
     name="pdf2docx",
-    version=get_version("version.txt"),
+    version=os.environ.get("PDF2DOCX_VERSION", get_version("version.txt")),
     keywords=["pdf-to-word", "pdf-to-docx"],
     description=DESCRIPTION,
     long_description=load_long_description("README.md"),
