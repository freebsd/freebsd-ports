--- cmake/TrMacros.cmake.orig	2026-01-31 10:47:49 UTC
+++ cmake/TrMacros.cmake
@@ -128,7 +128,142 @@ endfunction()
     set(${VAR_PREFIX}_DISALLOWED "${DISALLOWED_ITEMS}" PARENT_SCOPE)
 endfunction()
 
-macro(tr_add_external_auto_library ID DIRNAME LIBNAME)
+macro(tr_add_external_auto_library ID PACKAGENAME)
+    cmake_parse_arguments(_TAEAL_ARG
+        "SUBPROJECT;HEADER_ONLY"
+        "LIBNAME;SOURCE_DIR;TARGET"
+        "CMAKE_ARGS;COMPONENTS"
+        ${ARGN})
+
+    set(_TAEAL_SOURCE_DIR "${TR_THIRD_PARTY_SOURCE_DIR}")
+    set(_TAEAL_BINARY_DIR "${TR_THIRD_PARTY_BINARY_DIR}")
+    if (_TAEAL_ARG_SOURCE_DIR)
+        string(APPEND _TAEAL_SOURCE_DIR "/${_TAEAL_ARG_SOURCE_DIR}")
+        string(APPEND _TAEAL_BINARY_DIR "/${_TAEAL_ARG_SOURCE_DIR}.bld")
+    else()
+        string(APPEND _TAEAL_SOURCE_DIR "/${PACKAGENAME}")
+        string(APPEND _TAEAL_BINARY_DIR "/${PACKAGENAME}.bld")
+    endif()
+
+    if(USE_SYSTEM_${ID})
+        tr_get_required_flag(USE_SYSTEM_${ID} SYSTEM_${ID}_IS_REQUIRED)
+        set(_TAEAL_QUIET)
+        if(NOT SYSTEM_${ID}_IS_REQUIRED)
+            set(_TAEAL_QUIET QUIET)
+        endif()
+        find_package(${PACKAGENAME} ${${ID}_MINIMUM} ${SYSTEM_${ID}_IS_REQUIRED} ${_TAEAL_QUIET}
+            COMPONENTS ${_TAEAL_ARG_COMPONENTS})
+        tr_fixup_auto_option(USE_SYSTEM_${ID} ${PACKAGENAME}_FOUND SYSTEM_${ID}_IS_REQUIRED)
+    endif()
+
+    if(USE_SYSTEM_${ID})
+        unset(${PACKAGENAME}_UPSTREAM_TARGET)
+    elseif(_TAEAL_ARG_SUBPROJECT)
+        foreach(ARG IN LISTS _TAEAL_ARG_CMAKE_ARGS)
+            if(ARG MATCHES "^-D([^=: ]+)(:[^= ]+)?=(.*)$")
+                set(${CMAKE_MATCH_1} ${CMAKE_MATCH_3} CACHE INTERNAL "")
+            endif()
+        endforeach()
+
+        set(_TAEAL_SUBDIR_SYSTEM)
+        if(CMAKE_VERSION VERSION_GREATER_EQUAL 3.25)
+            set(_TAEAL_SUBDIR_SYSTEM SYSTEM)
+        endif()
+        add_subdirectory("${_TAEAL_SOURCE_DIR}" "${_TAEAL_BINARY_DIR}" EXCLUDE_FROM_ALL ${_TAEAL_SUBDIR_SYSTEM})
+    else()
+        if(NOT _TAEAL_ARG_LIBNAME)
+            message(FATAL_ERROR "LIBNAME must be specified if not SUBPROJECT")
+        endif ()
+
+        set(${PACKAGENAME}_UPSTREAM_TARGET "_${_TAEAL_ARG_LIBNAME}")
+        set(${PACKAGENAME}_PREFIX "${_TAEAL_BINARY_DIR}/pfx")
+
+        set(${PACKAGENAME}_INCLUDE_DIR "${${PACKAGENAME}_PREFIX}/include"
+            CACHE INTERNAL "")
+        set(${PACKAGENAME}_INCLUDE_DIRS ${${PACKAGENAME}_INCLUDE_DIR})
+
+        if(NOT _TAEAL_ARG_HEADER_ONLY)
+            set(${PACKAGENAME}_LIBRARY "${${PACKAGENAME}_PREFIX}/lib/${CMAKE_STATIC_LIBRARY_PREFIX}${_TAEAL_ARG_LIBNAME}${CMAKE_STATIC_LIBRARY_SUFFIX}"
+                CACHE INTERNAL "")
+            set(${PACKAGENAME}_LIBRARIES ${${PACKAGENAME}_LIBRARY})
+        endif()
+
+        set(${PACKAGENAME}_EXT_PROJ_CMAKE_ARGS)
+
+        if(APPLE)
+            string(REPLACE ";" "$<SEMICOLON>" ${PACKAGENAME}_CMAKE_OSX_ARCHITECTURES "${CMAKE_OSX_ARCHITECTURES}")
+            list(APPEND ${PACKAGENAME}_EXT_PROJ_CMAKE_ARGS
+                "-DCMAKE_OSX_ARCHITECTURES:STRING=${${PACKAGENAME}_CMAKE_OSX_ARCHITECTURES}"
+                "-DCMAKE_OSX_DEPLOYMENT_TARGET:STRING=${CMAKE_OSX_DEPLOYMENT_TARGET}"
+                "-DCMAKE_OSX_SYSROOT:PATH=${CMAKE_OSX_SYSROOT}")
+        endif()
+
+        if(ANDROID)
+            list(APPEND ${PACKAGENAME}_EXT_PROJ_CMAKE_ARGS
+                "-DANDROID_PLATFORM=${ANDROID_PLATFORM}"
+                "-DANDROID_NDK=${ANDROID_NDK}"
+                "-DANDROID_ABI=${ANDROID_ABI}"
+                "-DANDROID_STL=${ANDROID_STL}"
+                "-DCMAKE_ANDROID_NDK=${CMAKE_ANDROID_NDK}"
+                "-DCMAKE_ANDROID_ARCH_ABI=${CMAKE_ANDROID_ARCH_ABI}")
+        endif()
+
+        if(VCPKG_CHAINLOAD_TOOLCHAIN_FILE)
+            list(APPEND ${PACKAGENAME}_EXT_PROJ_CMAKE_ARGS
+                "-DVCPKG_CHAINLOAD_TOOLCHAIN_FILE=${VCPKG_CHAINLOAD_TOOLCHAIN_FILE}")
+        endif()
+
+        ExternalProject_Add(
+            ${${PACKAGENAME}_UPSTREAM_TARGET}
+            PREFIX "${_TAEAL_BINARY_DIR}"
+            SOURCE_DIR "${_TAEAL_SOURCE_DIR}"
+            INSTALL_DIR "${${PACKAGENAME}_PREFIX}"
+            CMAKE_ARGS
+                -Wno-dev # We don't want to be warned over unused variables
+                --no-warn-unused-cli
+                "-DCMAKE_TOOLCHAIN_FILE:PATH=${CMAKE_TOOLCHAIN_FILE}"
+                "-DCMAKE_USER_MAKE_RULES_OVERRIDE=${CMAKE_USER_MAKE_RULES_OVERRIDE}"
+                "-DCMAKE_C_COMPILER=${CMAKE_C_COMPILER}"
+                "-DCMAKE_C_FLAGS:STRING=${CMAKE_C_FLAGS}"
+                "-DCMAKE_CXX_COMPILER=${CMAKE_CXX_COMPILER}"
+                "-DCMAKE_CXX_FLAGS:STRING=${CMAKE_CXX_FLAGS}"
+                "-DCMAKE_BUILD_TYPE:STRING=${CMAKE_BUILD_TYPE}"
+                "-DCMAKE_INSTALL_PREFIX:PATH=<INSTALL_DIR>"
+                "-DCMAKE_INSTALL_LIBDIR:STRING=lib"
+                ${${PACKAGENAME}_EXT_PROJ_CMAKE_ARGS}
+                ${_TAEAL_ARG_CMAKE_ARGS}
+            BUILD_BYPRODUCTS "${${PACKAGENAME}_LIBRARY}")
+
+        set_property(TARGET ${${PACKAGENAME}_UPSTREAM_TARGET} PROPERTY FOLDER "${TR_THIRD_PARTY_DIR_NAME}")
+
+        # Imported target (below) requires include directories to be present at configuration time
+        file(MAKE_DIRECTORY ${${PACKAGENAME}_INCLUDE_DIRS})
+    endif()
+
+    if(NOT _TAEAL_ARG_SUBPROJECT AND _TAEAL_ARG_TARGET AND NOT TARGET ${_TAEAL_ARG_TARGET})
+        add_library(${_TAEAL_ARG_TARGET} INTERFACE IMPORTED)
+
+        target_include_directories(${_TAEAL_ARG_TARGET}
+            INTERFACE
+                ${${PACKAGENAME}_INCLUDE_DIRS})
+
+        if(NOT _TAEAL_ARG_HEADER_ONLY)
+            target_link_libraries(${_TAEAL_ARG_TARGET}
+                INTERFACE
+                    ${${PACKAGENAME}_LIBRARIES})
+        endif()
+
+        if(${PACKAGENAME}_UPSTREAM_TARGET)
+            add_dependencies(${_TAEAL_ARG_TARGET} ${${PACKAGENAME}_UPSTREAM_TARGET})
+        endif()
+    endif()
+
+    if(_TAEAL_ARG_TARGET AND NOT TARGET ${_TAEAL_ARG_TARGET})
+        message(FATAL_ERROR "Build system is misconfigured, this shouldn't happen! Can't find target '${_TAEAL_ARG_TARGET}'")
+    endif()
+endmacro()
+
+macro(tr_add_external_auto_library_legacy ID DIRNAME LIBNAME)
     cmake_parse_arguments(_TAEAL_ARG "SUBPROJECT" "TARGET" "CMAKE_ARGS" ${ARGN})
 
     if(USE_SYSTEM_${ID})
