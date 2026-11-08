--- phonemizer/backend/espeak/wrapper.py.orig	2026-09-17 05:22:22 UTC
+++ phonemizer/backend/espeak/wrapper.py
@@ -179,6 +179,7 @@ class EspeakWrapper:
           non-readable file
 
         """
+        return "%%LIBRARY%%"
         if cls._ESPEAK_LIBRARY:
             return cls._ESPEAK_LIBRARY
 
