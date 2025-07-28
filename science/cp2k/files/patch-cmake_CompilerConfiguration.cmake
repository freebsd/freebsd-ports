--- cmake/CompilerConfiguration.cmake.orig	2025-07-23 08:02:03 UTC
+++ cmake/CompilerConfiguration.cmake
@@ -53,9 +53,9 @@ add_compile_options(
 
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
@@ -67,9 +67,9 @@ add_compile_options(
 
 # Debug
 add_compile_options(
-  "$<$<AND:$<CONFIG:DEBUG>,$<COMPILE_LANG_AND_ID:Fortran,GNU>>:-O1;-march=native;-mtune=native>"
-  "$<$<AND:$<CONFIG:DEBUG>,$<COMPILE_LANG_AND_ID:CXX,GNU>>:-O1;-march=native;-mtune=native>"
-  "$<$<AND:$<CONFIG:DEBUG>,$<COMPILE_LANG_AND_ID:C,GNU>>:-O1;-march=native;-mtune=native>"
+  "$<$<AND:$<CONFIG:DEBUG>,$<COMPILE_LANG_AND_ID:Fortran,GNU>>:-O1>"
+  "$<$<AND:$<CONFIG:DEBUG>,$<COMPILE_LANG_AND_ID:CXX,GNU>>:-O1>"
+  "$<$<AND:$<CONFIG:DEBUG>,$<COMPILE_LANG_AND_ID:C,GNU>>:-O1>"
 )
 add_compile_options(
   "$<$<AND:$<CONFIG:DEBUG>,$<COMPILE_LANG_AND_ID:Fortran,GNU>>:-fsanitize=leak;-Werror=realloc-lhs>"
@@ -100,7 +100,7 @@ add_compile_options(
 
 # Address Sanitizer
 add_compile_options(
-  "$<$<CONFIG:ASAN>:-fsanitize=address;-no-pie;-O3;-march=native;-mtune=native;-funroll-loops>"
+  "$<$<CONFIG:ASAN>:-fsanitize=address;-no-pie;-O3;-funroll-loops>"
 )
 add_link_options("$<$<CONFIG:ASAN>:-fsanitize=address>")
 
