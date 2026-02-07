--- src/XspfReader.cpp.orig	2025-12-15 22:16:02 UTC
+++ src/XspfReader.cpp
@@ -61,9 +61,6 @@
 #include <cstring> // size_t
 #include <cstddef> // int
 
-#if (URI_VER_MINOR < 7) || ((URI_VER_MINOR == 7) && (URI_VER_RELEASE < 2))
-# error uriparser 0.7.2 or later is required
-#endif
 
 
 namespace {
