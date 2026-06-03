-- Fix shared-library OBJECT target dep resolution: allow non-proxygen external targets
-- (Folly::, mvfst::, fizz:: etc.) when no _obj version exists, while still avoiding
-- circular dependencies caused by proxygen INTERFACE wrappers linking to monolithic proxygen.
--- cmake/ProxygenFunctions.cmake.orig	2026-05-11 03:29:48 UTC
+++ cmake/ProxygenFunctions.cmake
@@ -432,10 +432,17 @@ function(proxygen_resolve_deferred_dependencies)
     foreach(_dep IN LISTS _deps)
       # For shared builds: if target is an OBJECT library (*_obj) and dep has an _obj version,
       # link to _obj for include path propagation
-      if(BUILD_SHARED_LIBS AND _target MATCHES "_obj$" AND TARGET ${_dep}_obj)
-        list(APPEND _valid_deps ${_dep}_obj)
-      elseif(BUILD_SHARED_LIBS AND _target MATCHES "_obj$")
-        # No _obj version exists; skip to avoid cycle through monolithic library
+      if(BUILD_SHARED_LIBS AND _target MATCHES "_obj$")
+        # In shared builds, OBJECT libraries must only link to other OBJECT libraries
+        # to avoid circular dependencies through INTERFACE wrappers that link to monolithic proxygen
+        if(TARGET ${_dep}_obj)
+          list(APPEND _valid_deps ${_dep}_obj)
+        elseif(NOT _dep MATCHES "^proxygen_")
+          # Allow non-proxygen targets (external deps like Folly::, mvfst::, etc.)
+          if(TARGET ${_dep})
+            list(APPEND _valid_deps ${_dep})
+          endif()
+        endif()
       elseif(TARGET ${_dep})
         list(APPEND _valid_deps ${_dep})
       endif()
