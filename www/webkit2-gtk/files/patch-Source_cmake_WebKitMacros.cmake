https://github.com/WebKit/WebKit/commit/4bfeff8c67ad47b7bb0f3d78390789f6f2af5dd2

--- Source/cmake/WebKitMacros.cmake.orig	2024-08-19 06:28:40 UTC
+++ Source/cmake/WebKitMacros.cmake
@@ -277,7 +277,7 @@ macro(_WEBKIT_TARGET_LINK_FRAMEWORK _target)
         get_property(_linked_into GLOBAL PROPERTY ${framework}_LINKED_INTO)
 
         # See if the target is linking a framework that the specified framework is already linked into
-        if ((NOT _linked_into) OR (${framework} STREQUAL ${_linked_into}) OR (NOT ${_linked_into} IN_LIST ${_target}_FRAMEWORKS))
+        if ((NOT _linked_into) OR (framework STREQUAL _linked_into) OR (NOT _linked_into IN_LIST ${_target}_FRAMEWORKS))
             list(APPEND ${_target}_PRIVATE_LIBRARIES WebKit::${framework})
 
             # The WebKit:: alias targets do not propagate OBJECT libraries so the
