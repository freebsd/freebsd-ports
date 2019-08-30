Look for the renamed libtidy.so from www/tidy-html and not pick up www/tidy-lib
by mistake

--- plugins/validators/FindLibTidy.cmake.orig	2019-08-30 19:38:08 UTC
+++ plugins/validators/FindLibTidy.cmake
@@ -28,7 +28,7 @@ endif( NOT LIBTIDY_INCLUDE_DIR )
 
 
 
-FIND_LIBRARY(LIBTIDY_LIBRARIES NAMES tidy)
+FIND_LIBRARY(LIBTIDY_LIBRARIES NAMES tidy5)
 
 if (LIBTIDY_INCLUDE_DIR AND LIBTIDY_LIBRARIES)
    set(LIBTIDY_FOUND TRUE)
