--- setup.py.orig	2024-02-06 04:58:53 UTC
+++ setup.py
@@ -71,7 +71,7 @@ googlefonts_extras = (
         # FontVersion.get_name_id5_version_string which was added in version 0.6.0
         f"fontTools[lxml,unicode]{FONTTOOLS_VERSION}",
         # (see https://github.com/googlefonts/gflanguages/pull/7)
-        "protobuf>=3.7.0, <4",  # 3.7.0 fixed a bug on parsing some METADATA.pb files.
+        "protobuf>=3.7.0",  # 3.7.0 fixed a bug on parsing some METADATA.pb files.
         # We cannot use v4 because our protobuf files have been compiled with v3.
         # (see https://github.com/fonttools/fontbakery/issues/2200)
     ]
@@ -179,7 +179,7 @@ setup(
         # ---
         # core dependencies
         f"fontTools{FONTTOOLS_VERSION}",
-        "freetype-py!=2.4.0",  # Avoiding 2.4.0 due to seg-fault described at
+        "freetype-py",  # Avoiding 2.4.0 due to seg-fault described at
         # https://github.com/fonttools/fontbakery/issues/4143
         "opentypespec",
         "opentype-sanitizer>=7.1.9",  # 7.1.9 fixes caret value format = 3 bug
