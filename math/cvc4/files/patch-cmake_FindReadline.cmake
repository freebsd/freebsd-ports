CMAKE_REQUIRED_INCLUDES does not work for some reason,
the check is compiled without the include path

--- cmake/FindReadline.cmake.orig	2019-04-09 16:14:31 UTC
+++ cmake/FindReadline.cmake
@@ -13,15 +13,7 @@ find_library(Readline_LIBRARIES NAMES readline)
 function(try_compile_readline libs _result)
   set(CMAKE_REQUIRED_QUIET TRUE)
   set(CMAKE_REQUIRED_LIBRARIES ${Readline_LIBRARIES} ${libs})
-  check_cxx_source_compiles(
-    "
-    #include <stdio.h>
-    #include <readline/readline.h>
-    int main() { readline(\"\"); return 0; }
-    "
-    ${_result}
-  )
-  set(${_result} ${${_result}} PARENT_SCOPE)
+  set(${_result} OK PARENT_SCOPE)
 endfunction()
 
 if(Readline_INCLUDE_DIR)
@@ -42,18 +34,7 @@ if(Readline_INCLUDE_DIR)
 
   # Check which standard of readline is installed on the system.
   # https://github.com/CVC4/CVC4/issues/702
-  include(CheckCXXSourceCompiles)
-  set(CMAKE_REQUIRED_QUIET TRUE)
-  set(CMAKE_REQUIRED_LIBRARIES ${Readline_LIBRARIES})
-  check_cxx_source_compiles(
-    "#include <stdio.h>
-     #include <readline/readline.h>
-     char* foo(const char*, int) { return (char*)0; }
-     int main() { rl_completion_entry_function = foo; return 0; }"
-     Readline_COMPENTRY_FUNC_RETURNS_CHARPTR
-  )
-  unset(CMAKE_REQUIRED_QUIET)
-  unset(CMAKE_REQUIRED_LIBRARIES)
+  set(Readline_COMPENTRY_FUNC_RETURNS_CHARPTR TRUE)
 endif()
 
 include(FindPackageHandleStandardArgs)
