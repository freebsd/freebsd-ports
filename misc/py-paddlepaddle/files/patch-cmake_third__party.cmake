--- cmake/third_party.cmake.orig	2025-12-26 03:31:02 UTC
+++ cmake/third_party.cmake
@@ -36,25 +36,8 @@ if(NOT WITH_SETUP_INSTALL)
 ProcessorCount(NPROC)
 if(NOT WITH_SETUP_INSTALL)
   #NOTE(risemeup1):Initialize any submodules.
-  message(
-    STATUS
-      "Check submodules of paddle, and run 'git submodule sync --recursive && git submodule update --init --recursive'"
-  )
 
-  # execute_process does not support sequential commands, so we execute echo command separately
-  execute_process(
-    COMMAND git submodule sync --recursive
-    WORKING_DIRECTORY ${PADDLE_SOURCE_DIR}
-    RESULT_VARIABLE result_var)
-  if(NOT result_var EQUAL 0)
-    message(FATAL_ERROR "Failed to sync submodule, please check your network !")
-  endif()
-
   if(WITH_OPENVINO)
-    execute_process(
-      COMMAND git submodule update --init --depth=1 third_party/openvino
-      WORKING_DIRECTORY ${PADDLE_SOURCE_DIR}
-      RESULT_VARIABLE result_var)
     # List of modules to be deleted
     set(delete_module
         "thirdparty/zlib/zlib"
@@ -75,65 +58,9 @@ if(NOT WITH_SETUP_INSTALL)
         "thirdparty/level_zero/level-zero"
         "src/plugins/intel_npu/thirdparty/level-zero-ext"
         "src/plugins/intel_npu/thirdparty/yaml-cpp")
-    # Iterate over each module and perform actions
-    foreach(module IN LISTS delete_module)
-      # Remove the module from git cache
-      execute_process(
-        COMMAND git rm --cached ${module}
-        WORKING_DIRECTORY ${PADDLE_SOURCE_DIR}/third_party/openvino
-        RESULT_VARIABLE git_rm_result)
-    endforeach()
-    execute_process(
-      COMMAND git submodule update --init --recursive
-      WORKING_DIRECTORY ${PADDLE_SOURCE_DIR}
-      RESULT_VARIABLE result_var)
   else()
-    execute_process(
-      COMMAND git submodule status
-      WORKING_DIRECTORY ${PADDLE_SOURCE_DIR}
-      OUTPUT_VARIABLE submodule_list
-      RESULT_VARIABLE result_var)
     string(REGEX MATCHALL "third_party/[^ )\n]+" submodule_paths
                  "${submodule_list}")
-    foreach(submodule IN LISTS submodule_paths)
-      if(NOT submodule STREQUAL "third_party/openvino")
-        execute_process(
-          COMMAND git submodule update --init --recursive ${submodule}
-          WORKING_DIRECTORY ${PADDLE_SOURCE_DIR}
-          RESULT_VARIABLE result_var)
-      endif()
-    endforeach()
-  endif()
-  if(NOT result_var EQUAL 0)
-    if(${CMAKE_SYSTEM_NAME} MATCHES "Linux")
-      set(THIRD_PARTY_TAR_URL
-          https://xly-devops.bj.bcebos.com/PR/build_whl/0/third_party.tar.gz
-          CACHE STRING "third_party.tar.gz url")
-      execute_process(
-        COMMAND wget -q ${THIRD_PARTY_TAR_URL}
-        WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
-        RESULT_VARIABLE wget_result)
-      if(NOT wget_result EQUAL 0)
-        message(
-          FATAL_ERROR
-            "Failed to download third_party.tar.gz, please check your network !"
-        )
-      else()
-        execute_process(
-          COMMAND tar -xzf third_party.tar.gz -C ${CMAKE_SOURCE_DIR}/
-          WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
-          RESULT_VARIABLE tar_result)
-        if(NOT tar_result EQUAL 0)
-          message(
-            FATAL_ERROR
-              "Failed to extract third_party.tar.gz, please make sure tar.gz file is not corrupted !"
-          )
-        endif()
-      endif()
-    else()
-      message(
-        FATAL_ERROR "Failed to update submodule, please check your network !")
-    endif()
   endif()
 
 endif()
