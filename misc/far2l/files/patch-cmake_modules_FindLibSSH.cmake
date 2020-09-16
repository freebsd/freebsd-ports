--- cmake/modules/FindLibSSH.cmake.orig	2020-06-22 23:39:14 UTC
+++ cmake/modules/FindLibSSH.cmake
@@ -61,15 +61,20 @@ else (LIBSSH_LIBRARIES AND LIBSSH_INCLUDE_DIRS)
             )
 
         if (LibSSH_FIND_VERSION)
-            file(STRINGS ${LIBSSH_INCLUDE_DIR}/libssh/libssh.h LIBSSH_VERSION_MAJOR
+            # libssh >= 0.9.5 provides dedicated version header file
+            set(_libssh_version_header ${LIBSSH_INCLUDE_DIR}/libssh/libssh_version.h)
+            if (NOT EXISTS ${_libssh_version_header})
+                set(_libssh_version_header ${LIBSSH_INCLUDE_DIR}/libssh/libssh.h)
+            endif()
+            file(STRINGS ${_libssh_version_header} LIBSSH_VERSION_MAJOR
                 REGEX "#define[ ]+LIBSSH_VERSION_MAJOR[ ]+[0-9]+")
             # Older versions of libssh like libssh-0.2 have LIBSSH_VERSION but not LIBSSH_VERSION_MAJOR
             if (LIBSSH_VERSION_MAJOR)
                 string(REGEX MATCH "[0-9]+" LIBSSH_VERSION_MAJOR ${LIBSSH_VERSION_MAJOR})
-                file(STRINGS ${LIBSSH_INCLUDE_DIR}/libssh/libssh.h LIBSSH_VERSION_MINOR
+                file(STRINGS ${_libssh_version_header} LIBSSH_VERSION_MINOR
                     REGEX "#define[ ]+LIBSSH_VERSION_MINOR[ ]+[0-9]+")
                 string(REGEX MATCH "[0-9]+" LIBSSH_VERSION_MINOR ${LIBSSH_VERSION_MINOR})
-                file(STRINGS ${LIBSSH_INCLUDE_DIR}/libssh/libssh.h LIBSSH_VERSION_PATCH
+                file(STRINGS ${_libssh_version_header} LIBSSH_VERSION_PATCH
                     REGEX "#define[ ]+LIBSSH_VERSION_MICRO[ ]+[0-9]+")
                 string(REGEX MATCH "[0-9]+" LIBSSH_VERSION_PATCH ${LIBSSH_VERSION_PATCH})
 
