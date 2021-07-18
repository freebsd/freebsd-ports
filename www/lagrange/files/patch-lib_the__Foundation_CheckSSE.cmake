Disable SSE4.1 by default and make it opt-in only.

Older class AMD64 and i386 CPUs do not support the
feature-set, this becomes a problem when a build
hosts support it, whilst package consumers do not,
causing an instant crash upon startup.

--- lib/the_Foundation/CheckSSE.cmake.orig	2021-04-22 10:39:48 UTC
+++ lib/the_Foundation/CheckSSE.cmake
@@ -1,22 +1 @@
 set (SSE41_FOUND NO)
-try_run (
-    sseRunCode
-    sseCompiled
-    ${CMAKE_CURRENT_BINARY_DIR}
-    ${CMAKE_CURRENT_LIST_DIR}/ssecheck.c
-    RUN_OUTPUT_VARIABLE sseOutput
-)
-string (STRIP "${sseOutput}" sseOutput)
-# message (STATUS "sseCompiled: ${sseCompiled}")
-# message (STATUS "sseRunCode: ${sseRunCode}")
-# message (STATUS "sseOutput: ${sseOutput}")
-
-if (sseCompiled AND sseOutput STREQUAL "1")
-    set (SSE41_FOUND YES)
-endif ()
-
-if (SSE41_FOUND)
-    message (STATUS "CPU supports SSE 4.1")
-else ()
-    message (STATUS "CPU does not support SSE 4.1")
-endif ()
