--- cmake/CompilerConfiguration.cmake.orig	2026-01-06 09:31:20 UTC
+++ cmake/CompilerConfiguration.cmake
@@ -51,9 +51,9 @@ add_compile_options(
 
 # Release
 add_compile_options(
-  "$<$<AND:$<CONFIG:RELEASE>,$<COMPILE_LANG_AND_ID:Fortran,GNU>>:-O3;-march=native;-mtune=native;-funroll-loops>"
-  "$<$<AND:$<CONFIG:RELEASE>,$<COMPILE_LANG_AND_ID:CXX,GNU>>:-O3;-march=native;-mtune=native;-funroll-loops>"
-  "$<$<AND:$<CONFIG:RELEASE>,$<COMPILE_LANG_AND_ID:C,GNU>>:-O3;-march=native;-mtune=native;-funroll-loops>"
+  "$<$<AND:$<CONFIG:RELEASE>,$<COMPILE_LANG_AND_ID:Fortran,GNU>>:-O3;-funroll-loops>"
+  "$<$<AND:$<CONFIG:RELEASE>,$<COMPILE_LANG_AND_ID:CXX,GNU>>:-O3;-funroll-loops>"
+  "$<$<AND:$<CONFIG:RELEASE>,$<COMPILE_LANG_AND_ID:C,GNU>>:-O3;-funroll-loops>"
 )
 
 # Generic
@@ -65,9 +65,9 @@ add_compile_options(
 
 # Debug
 add_compile_options(
-  "$<$<AND:$<CONFIG:DEBUG>,$<COMPILE_LANG_AND_ID:Fortran,GNU>>:-O1;-march=native;-mtune=native>"
-  "$<$<AND:$<CONFIG:DEBUG>,$<COMPILE_LANG_AND_ID:CXX,GNU>>:-O1;-march=native;-mtune=native>"
-  "$<$<AND:$<CONFIG:DEBUG>,$<COMPILE_LANG_AND_ID:C,GNU>>:-O1;-march=native;-mtune=native;-Wall;-Wextra;-Werror>"
+  "$<$<AND:$<CONFIG:DEBUG>,$<COMPILE_LANG_AND_ID:Fortran,GNU>>:-O1>"
+  "$<$<AND:$<CONFIG:DEBUG>,$<COMPILE_LANG_AND_ID:CXX,GNU>>:-O1>"
+  "$<$<AND:$<CONFIG:DEBUG>,$<COMPILE_LANG_AND_ID:C,GNU>>:-O1>"
 )
 add_compile_options(
   "$<$<AND:$<CONFIG:DEBUG>,$<COMPILE_LANG_AND_ID:Fortran,GNU>>:-fsanitize=leak;-Werror=realloc-lhs>"
@@ -107,7 +107,7 @@ add_compile_options(
 
 # Address Sanitizer
 add_compile_options(
-  "$<$<CONFIG:ASAN>:-fsanitize=address;-no-pie;-O3;-march=native;-mtune=native;-funroll-loops>"
+  "$<$<CONFIG:ASAN>:-fsanitize=address;-no-pie;-O3;-funroll-loops>"
 )
 add_link_options("$<$<CONFIG:ASAN>:-fsanitize=address>")
 
