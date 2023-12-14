--- setup.py.orig	2023-12-01 14:46:39 UTC
+++ setup.py
@@ -72,7 +72,7 @@ googlefonts_extras = (
         # FontVersion.get_name_id5_version_string which was added in version 0.6.0
         f"fontTools[lxml,unicode]{FONTTOOLS_VERSION}",
         # (see https://github.com/googlefonts/gflanguages/pull/7)
-        "protobuf>=3.7.0, <4",  # 3.7.0 fixed a bug on parsing some METADATA.pb files.
+        "protobuf>=3.7.0",  # 3.7.0 fixed a bug on parsing some METADATA.pb files.
         # We cannot use v4 because our protobuf files have been compiled with v3.
         # (see https://github.com/fonttools/fontbakery/issues/2200)
         f"vharfbuzz{VHARFBUZZ_VERSION}",
@@ -122,7 +122,7 @@ all_extras = set(
 
 setup(
     name="fontbakery",
-    use_scm_version={"write_to": "Lib/fontbakery/_version.py"},
+    use_scm_version={"fallback_version": "%%PORTVERSION%%", "write_to": "Lib/fontbakery/_version.py"},
     url="https://github.com/fonttools/fontbakery/",
     description="A font quality assurance tool for everyone",
     long_description=readme,
@@ -183,7 +183,7 @@ setup(
         # core dependencies
         "babelfont>=3.0.1",  # v3.0.1 needed by check/legacy_accents
         f"fontTools{FONTTOOLS_VERSION}",
-        "freetype-py!=2.4.0",  # Avoiding 2.4.0 due to seg-fault described at
+        "freetype-py",  # Avoiding 2.4.0 due to seg-fault described at
         # https://github.com/fonttools/fontbakery/issues/4143
         "opentypespec",
         "opentype-sanitizer>=7.1.9",  # 7.1.9 fixes caret value format = 3 bug
