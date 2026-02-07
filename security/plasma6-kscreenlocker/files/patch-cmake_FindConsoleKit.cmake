--- cmake/FindConsoleKit.cmake.orig	2023-11-29 10:41:23 UTC
+++ cmake/FindConsoleKit.cmake
@@ -4,7 +4,7 @@ find_program(cklistsessions_EXECUTABLE NAMES ck-list-s
 # SPDX-License-Identifier: BSD-3-Clause
 #=============================================================================
 find_program(cklistsessions_EXECUTABLE NAMES ck-list-sessions)
-find_program(qdbus_EXECUTABLE NAMES qdbus)
+find_program(qdbus_EXECUTABLE NAMES qdbus6 qdbus)
 find_package_handle_standard_args(ConsoleKit
     FOUND_VAR
         ConsoleKit_FOUND
