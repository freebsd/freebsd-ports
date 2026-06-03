--- test/test_espeak.py.orig	2024-01-01 00:00:00 UTC
+++ test/test_espeak.py
@@ -116,16 +116,6 @@ def test_phone_separator_simple():
     'PHONEMIZER_ESPEAK_LIBRARY' in os.environ,
     reason='cannot modify environment')
 def test_path_good():
-    espeak = EspeakBackend.library()
-    try:
-        EspeakBackend.set_library(None)
-        assert espeak == EspeakBackend.library()
-
-        library = EspeakWrapper().library_path
-        EspeakBackend.set_library(library)
-
-        test_english()
-
-    # restore the espeak path to default
-    finally:
-        EspeakBackend.set_library(None)
+    # Skip on FreeBSD - default library path is patched, so resetting to None
+    # doesn't return the same value as before (full path vs soname)
+    pytest.skip("Test not applicable on FreeBSD due to patched library path")
