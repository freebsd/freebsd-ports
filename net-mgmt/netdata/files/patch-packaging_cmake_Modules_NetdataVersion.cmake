--- packaging/cmake/Modules/NetdataVersion.cmake.orig	2025-05-28 22:57:38 UTC
+++ packaging/cmake/Modules/NetdataVersion.cmake
@@ -5,22 +5,23 @@ function(netdata_version)
 # packaging/version. This version field are used for cmake's project,
 # cpack's packaging, and the agent's functionality.
 function(netdata_version)
-        find_package(Git)
+        #find_package(Git)
 
-        if(GIT_EXECUTABLE)
-                execute_process(COMMAND ${GIT_EXECUTABLE} describe
-                                WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
-                                RESULT_VARIABLE GIT_DESCRIBE_RESULT
-                                OUTPUT_VARIABLE GIT_DESCRIBE_OUTPUT)
-                if(GIT_DESCRIBE_RESULT)
-                        file(STRINGS "${CMAKE_SOURCE_DIR}/packaging/version" GIT_DESCRIBE_OUTPUT)
-                        message(WARNING "using version from packaging/version: '${GIT_DESCRIBE_OUTPUT}'")
-                endif()
-        else()
-                file(STRINGS packaging/version GIT_DESCRIBE_OUTPUT)
-                message(WARNING "using version from packaging/version: '${GIT_DESCRIBE_OUTPUT}'")
-        endif()
+        #if(GIT_EXECUTABLE)
+        #        execute_process(COMMAND ${GIT_EXECUTABLE} describe
+        #                        WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
+        #                        RESULT_VARIABLE GIT_DESCRIBE_RESULT
+        #                        OUTPUT_VARIABLE GIT_DESCRIBE_OUTPUT)
+        #        if(GIT_DESCRIBE_RESULT)
+        #                file(STRINGS "${CMAKE_SOURCE_DIR}/packaging/version" GIT_DESCRIBE_OUTPUT)
+        #                message(WARNING "using version from packaging/version: '${GIT_DESCRIBE_OUTPUT}'")
+        #        endif()
+        #else()
+        #        file(STRINGS packaging/version GIT_DESCRIBE_OUTPUT)
+        #        message(WARNING "using version from packaging/version: '${GIT_DESCRIBE_OUTPUT}'")
+        #endif()
 
+        set(GIT_DESCRIBE_OUTPUT "v%%DISTVERSION%%")
         string(STRIP ${GIT_DESCRIBE_OUTPUT} GIT_DESCRIBE_OUTPUT)
         set(NETDATA_VERSION_STRING "${GIT_DESCRIBE_OUTPUT}" PARENT_SCOPE)
 
